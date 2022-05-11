#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char input[100];
  List *history = init_history();
  char test;
  while (1) {
    printf("\nTo quit enter 'q' To type sentence into tokenizer type 't' To find spot 'i' in history  type '!i' To check all history type 'h'");

    putchar('$');
    fgets(input, 100, stdin);
    printf(input);

    
    /*
    // input is a pointer so acces with input[0]
    // We're having '!' initiate commands
    test = input[0];
    printf("%c is a space: %d\n", test, space_char(test));
    */

    if (input[0] == 'q') {
      printf("Thanks for using tokenizer");
      free_history(history);
      return 0;
    }

    else if(input[0] == 't') {
      printf("Please enter your sentence: ");

      putchar('$');
      fgets(input,100,stdin);
      char **tokens = tokenize(input);
      add_history(history, input);
      free_tokens(tokens);
    }

    else if (input[0] = '!') {
      char *hist = get_history(history, atoi(input+1));
      char **tokens = tokenize(hist);

      printf("Retrieved: %s\n", hist);
      printf("Tokenized: %s\n", tokens);

      print_tokens(tokens);
      free_tokens(tokens);
    }

    else if (input[0] == 'h') {
      print_history(history);
    }

    else {
      printf("Request is not valid\n");
    }
    
    
  }
}
