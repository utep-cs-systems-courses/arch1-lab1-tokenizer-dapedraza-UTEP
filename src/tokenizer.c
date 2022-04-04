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
