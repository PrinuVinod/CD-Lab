// Correct implementation of DFA is as follows:
// This is a dfa problem that accepts string with 1 or 0 and ending with '11'.

#include <stdio.h>
#include <string.h>

int main()
{
    char string[20];
    int n, state = 0, final_state;

    // Prompt user to input a string
    printf("Enter the string to be checked: ");
    gets(string);

    // Find the length of the input string
    n = strlen(string);

    // Loop through each character in the string
    for (int i = 0; i < n; i++)
    {
        // The switch case handles transitions based on the current character
        switch (string[i])
        {
        case '1':
            // Transition rules for '1' based on the current state
            if (state == 0)
            {
                state = 1;
            }
            else if (state == 1)
            {
                state = 2;
            }
            break;
        case '0':
            // Transition rules for '0' based on the current state
            if (state == 0)
            {
                state = 0;
            }
            else if (state == 1)
            {
                state = 0;
            }
            else if (state == 2)
            {
                state = 0;
            }
            break;
        default:
            // If the input contains characters other than '0' or '1', it's invalid
            printf("Invalid string!");
            return 1;
        }

        // Check if the final state is reached and it's the last character in the string
        if (state == 2 && i == n - 1)
        {
            printf("\nString is valid!\n");
            return 0;
        }
    }

    // If the loop completes and the final state is not reached, the string is invalid
    printf("\nString is invalid!\n");
    return 0;
}

// This is an udayipp code that accepts string with 1 or 0 and ending with '10'.

// #include<stdio.h>
// #include<string.h>

// int main() {
//     char string[20];
//     int n;

//     printf("Enter the string to be checked: ");
//     gets(string);

//     n = strlen(string);
//     for(int i=0; i<n; i++) {
//         if(string[i] != '1' && string[i] != '0') {
//             printf("Invalid string!");
//             return 1;
//         }
//     }

//     if (string[n-2] == '1' && string[n-1] == '0')
//     {
//         printf("\nString is valid!\n");
//     } else {
//         printf("\nString is invalid!\n");
//     }
//     return 0;
// }