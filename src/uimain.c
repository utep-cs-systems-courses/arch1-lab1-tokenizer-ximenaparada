#include <stdio.h>

int main()
{
  char input[100];
  
  while (1) {
    
    putchar('$');
    fgets(input, 100, stdin);
    printf(input);

    // input is a pointer so acces with input[0]
    // We're having '!' initiate commands
    
    if(input[0] == '!'){
      if (input[1] == 'q') {
	return 0;
      }
    }
    
  }
  return 0;
}
