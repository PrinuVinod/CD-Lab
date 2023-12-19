#include <stdio.h>
#include <string.h>
#include <ctype.h>

int z = 0, i = 0, j = 0, c = 0;
char inputString[16], stack[15];

void check();

void main()
{
	printf("\nGRAMMAR :\n E->E+E \n E->E*E \n E->E/E \n E->a\n E->b\n");

	printf("Enter input string: ");
	gets(inputString);

	c = strlen(inputString);

	printf("Stack \t Input \t\t Action");
	for (i = 0, j = 0; j < c; i++, j++)
	{
		stack[i] = inputString[j];
		stack[i + 1] = '\0';
		inputString[j] = ' ';
		printf("\n$%s\t%s$\t%s %c", stack, inputString, "SHIFT", stack[i]);
		check();
	}
	printf("\n\n");

	if (strcmp(stack, "E") == 0)
	{
		printf("The input is valid and accepted\n\n");
	}
	else
		printf("Invalid Input\n\n");
}

void check()
{
	for (z = 0; z < c; z++)
	{
		if (stack[z] == 'a' || stack[z] == 'b')
		{
			stack[z] = 'E';
			printf("\n$%s\t%s$\t%s", stack, inputString, "REDUCE TO E");
			break;
		}
	}
	for (z = 0; z < c; z++)
	{
		if ((stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E') ||
			(stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E') ||
			(stack[z] == 'E' && stack[z + 1] == '/' && stack[z + 2] == 'E') ||
			(stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')'))
		{
			stack[z] = 'E';
			stack[z + 1] = '\0';
			stack[z + 2] = '\0';
			printf("\n$%s\t%s$\t%s", stack, inputString, "REDUCE TO E");
			i = i - 2;
		}
	}
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int z = 0, i = 0, j = 0, c = 0;
// char inputString[16], stk[15];

// void check();
// void replaceandprint();

// void main()
// {
// 	// Display the given grammar rules
// 	printf("\nGRAMMAR :\n E->E+E \n E->E*E \n E->E/E \n E->a\n E->b\n");

// 	// Prompt the user to enter an input string
// 	puts("Enter input string: ");
// 	gets(inputString);

// 	// Get the length of the input string
// 	c = strlen(inputString);

// 	// Display the table headers
// 	puts("Stack \t Input \t\t Action");

// 	// Loop through the input string
// 	for (i = 0, j = 0; j < c; i++, j++)
// 	{
// 		// Push the current character onto the stack
// 		stk[i] = inputString[j];
// 		stk[i + 1] = '\0';
// 		inputString[j] = ' ';

// 		// Display the current stack, input, and the action (SHIFT)
// 		printf("\n$%s\t%s$\t%s %c", stk, inputString, "SHIFT", stk[i]);

// 		// Check if any reduction is possible
// 		check();
// 	}

// 	printf("\n\n");

// 	// Check if the final stack contains only 'E'
// 	if (strcmp(stk, "E") == 0)
// 	{
// 		printf("The input is valid and accepted\n\n");
// 	}
// 	else
// 	{
// 		printf("Invalid Input\n\n");
// 	}
// }

// void check()
// {
// 	// Check for terminals 'a' or 'b' in the stack
// 	for (z = 0; z < c; z++)
// 	{
// 		if (stk[z] == 'a' || stk[z] == 'b')
// 		{
// 			// Replace terminals 'a' or 'b' with 'E' and print the reduction
// 			replaceandprint();
// 			i = i + 2;
// 			break;
// 		}
// 	}

// 	// Check for productions in the stack and replace them with 'E'
// 	for (z = 0; z < c; z++)
// 	{
// 		if ((stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') ||
// 			(stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') ||
// 			(stk[z] == 'E' && stk[z + 1] == '/' && stk[z + 2] == 'E') ||
// 			(stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')'))
// 		{
// 			// Replace the production with 'E' and print the reduction
// 			replaceandprint();
// 		}
// 	}
// }

// void replaceandprint()
// {
// 	// Replace part of the stack with 'E'
// 	stk[z] = 'E';
// 	stk[z + 1] = '\0';
// 	stk[z + 2] = '\0';

// 	// Display the current stack, input, and the action (REDUCE TO E)
// 	printf("\n$%s\t%s$\t%s", stk, inputString, "REDUCE TO E");

// 	// Adjust the index to account for the reduction
// 	i = i - 2;
// }