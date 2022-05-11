#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>
#include <stdio.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  if (c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c) {
  if (c == '\t' || c == ' ') {  // Add null
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  // NOTE: ptr+i -> address; *(ptr+i) -> content
  int i = 0;
  while (*(str + i)) {  // for-loop: traversing str in a a[i] form
    if (non_space_char(*(str + i))) {  // if curr char not space return as beginning of word
      return str + i;
    }
    i++;  // add onto position var i
  }
  return str + i;  // if traveresed str w/o finding; ret end
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  // NOTE: ptr+i -> address; *(ptr+i) -> content
  int i = 0;
  while (non_space_char(*(word+i))) {
      if (space_char(*(word + i + 1)))
      // if curr char not space and next is space; return as end of word
	return word + i + 1;
      else
	i++;  // add onto position var i
  }
  return word + i;  // if traveresed str w/o finding; ret end
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  int count = 0;
  int curr = 0;

  while (*str != '\0') {
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char *ptr;
  ptr = (char*)malloc(sizeof(char) * (len + 1)); // alloc size of 'array' each cell char sized, len of them

  for (int i = 0; i < len; i++) {
    *(ptr + i) = *(inStr + i);    // adding each char into ptr (like an array)
  }
  *(ptr + len) = '\0';  // location len already past the word, we store terminator char '\0'

  return (ptr);  // return ptr 'array'
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int num_tokens = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*) * num_tokens + 1);
  char *start;
  char *end;
  int length;

  end = word_start(str);  // used to help keep a recursive structure inside for loop
  for(int i = 0; i < num_tokens; i++) {
    start = word_start(end);  // at first starts from 0 ^, then will start from last word end
    end = word_terminator(start);  // find end of curr word from curr start pos
    length = end - start;  // len of word = end - beginning

    *(tokens + i) = copy_str(start, length);  // copying word to token location i
    // printf("token[%d] = %s\n", i, *(tokens + i));   // token[0] = word
  }
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int id = 0;
  while (*tokens) {
    printf("tonek[%d] = %s\n", id, *tokens);
    id++;
    *tokens++;  // advancing token/array location tokens[loc + 1]
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  int id = 0;
  while (*(tokens + id)) {   // while there IS something to free inside token array[id] -> usually checking one step ahead
    free(*(tokens + id));  // freen token at loc id -> token[id]
    id++;
  }
  free(tokens);  // once **tokens empty, free mem alloc for ptr.
}

