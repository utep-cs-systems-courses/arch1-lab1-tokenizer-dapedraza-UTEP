#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  while(1) {
    char str[100];
    fputs(">", stdout);
    fgets(str, sizeof(str), stdin);
    puts(str);

    goto done;
  }

 done://end of ui
  return 0;
}
