#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  return c == ' ' || c == '\t';
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
  return c != ' ' && c != '\t' && c != '\0';
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  int i = 0;
  while(str[i]) {
    if(non_space_char(str[i]))
      return str + i;;
    i++;
  }

  return 0;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  int i = 0;
  while(non_space_char(word[i])){
    i++;
  }

  return word + i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  int count = 0;
  
  while(*str){
    str = word_start(str);
    if(str) {
      count++;
      str = word_terminator(str);
    }
  }

  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char *copy;
  copy = (char *) malloc(sizeof(char) * (len + 1));

  int i;
  for(i = 0; i <= len; i++)
    copy[i] = inStr[i];

  copy[i] = '\0';

  return copy;
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str) {
  int wordNum = count_words(str);
  char **tokens;
  tokens = (char **) malloc(sizeof(char) * (wordNum + 1));

  int wordLen; //length of the word to put into copy_str
  int *wordSt; //pointer to the start of the word
  int *wordEnd; //pointer to the end of the word
  wordSt = word_start(str); //initialize a pointer to the start of str
  for(int i = 0; i < wordNum; i++) {
    wordEnd = word_terminator(wordSt);
    wordLen = wordEnd - wordSt;
    tokens[i] = copy_str(wordSt, wordLen);
    wordSt = word_start(wordEnd);
  }
  tokens[i] = '\0';

  return tokens;
}
