#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

#include <string.h>



/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){

  if( c == ' ' || c == '\t' || c == '\0' ){

        return 1;

      }else return 0;

}



/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */ 

int non_space_char(char c){

  if(c != ' ' || c == '\t'){

    return 1;

  }else return 0;

}



/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */

char *word_start(char *str){

  int i = 0;

  while( str[i] != '\0' && i <= 100 ){

    if( non_space_char(str[i]) ){

      return str;

    }

    i++;

  }



  return 0;

  }



/* Returns a pointer terminator char following *word */

char *word_terminator(char *word){

  int i = 1;

  char *wordEnd;



  while( word[i] != '\0' && i <= 100 ){

    if( space_char(word[i]) && non_space_char(word[i-1]) ){

      wordEnd = &word[i];

      return wordEnd;

    }

    i++;

  }

  return 0;

}



/* Counts the number of words in the string argument. */

int count_words(char *str){

  int i = 0;

  int wordCount = 0;



  while(str[i] != '\0' && i <= 100){



    if(non_space_char(str[i]) && space_char(str[i + 1]) ){

      wordCount++;

    }

    i++;

  }

  return wordCount;

}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){

  char *str;

  str = (char*)malloc(len+1);



  while(*str){

    *str = *inStr;

    str++;

    inStr++;

  }



  char *ret = str;

  return ret;

}



/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char *str){

  int wordCount = (short)count_words(str);

  char *array[wordCount];

  char **ppTokens;

  char *pStart;

  int i = 0;

  int strLength = 0;



  while( str[i] != '\0' && i <= 50){

    pStart = word_start(str);

    if( non_space_char(str[i]) ){

      strLength++;

    }

    

    array[i] = copy_str(pStart, strLength);

    i++;

  }

  ppTokens = array;

  return ppTokens;

}



/* Prints all tokens. */

void print_tokens(char **tokens){

  int i = 0;

  while( tokens[i] != '\0'){

    printf("Print Tokens: %s\n", *tokens);

    i++;

  }

}



/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens);



int main()

{

   int check_space;

   char input[100];

    // Input from User for the weight

    printf("Please enter a string:\n>");

    scanf("%[^\n]", input);

    printf("your input: %s\n", input);

    

    char **tokens;
    tokens = tokenize(input);

    print_tokens(tokens);

    

    return 0;

}
