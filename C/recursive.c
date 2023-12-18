#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[10];
int i = 0, error = 0;

void E();
void T();
void Eprime();
void Tprime();
void F();

void main()
{
     // Prompt user to enter an arithmetic expression
     printf("Enter an arithmetic expression: ");
     // Read the input expression into the 'input' array
     scanf("%s", input);
     // Call the starting non-terminal E to begin parsing
     E();
     // Check if the entire input is consumed and no errors occurred
     if (strlen(input) == i && error == 0)
          printf("\nAccepted\n");
     else
          printf("\nRejected\n");
}

void E()
{
     // Call non-terminal T
     T();
     // Call non-terminal Eprime
     Eprime();
}

void Eprime()
{
     // Check for '+' in the input
     if (input[i] == '+')
     {
          // Consume '+' and move to the next character
          i++;
          // Call non-terminal T
          T();
          // Recursively call Eprime
          Eprime();
     }
}

void T()
{
     // Call non-terminal F
     F();
     // Call non-terminal Tprime
     Tprime();
}

void Tprime()
{
     // Check for '*' in the input
     if (input[i] == '*')
     {
          // Consume '*' and move to the next character
          i++;
          // Call non-terminal F
          F();
          // Recursively call Tprime
          Tprime();
     }
}

void F()
{
     // Check if the current character is alphanumeric
     if (isalnum(input[i]))
          // Consume the alphanumeric character and move to the next character
          i++;
     // Check if the current character is '('
     else if (input[i] == '(')
     {
          // Consume '(' and move to the next character
          i++;
          // Call non-terminal E
          E();
          // Check if the current character is ')'
          if (input[i] == ')')
               // Consume ')' and move to the next character
               i++;
          else
               // Set error flag if ')' is expected but not found
               error = 1;
     }
     // Set error flag if the current character doesn't match any expected pattern
     else
          error = 1;
}
