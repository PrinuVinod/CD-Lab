#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Global variables
int n, m = 0, i = 0, j = 0;
char a[10][10], f[10];

// Function prototypes
void follow(char c);
void first(char c);

int main()
{
    int z;
    char c, ch;

    // User input: number of productions
    printf("Enter the no of productions:\n");
    scanf("%d", &n);

    // User input: productions
    printf("Enter the productions:\n");
    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    do
    {
        m = 0;

        // User input: non-terminal for which FIRST and FOLLOW sets are to be found
        printf("\n\nEnter the elements whose first and follow is to be found:");
        scanf(" %c", &c); // Added a space before %c to consume any leading whitespace

        // Compute and print FIRST set
        first(c);
        printf("First(%c) = {", c);
        for (i = 0; i < m; i++)
            printf(" %c", f[i]);
        printf("}\n");

        // Reset the array f
        strcpy(f, " ");

        m = 0;

        // Compute and print FOLLOW set
        follow(c);
        printf("Follow(%c)={", c);
        for (i = 0; i < m; i++)
            printf("%c", f[i]);
        printf("}\n");

        // User input: continue or not
        printf("Continue(0/1)?");
        scanf("%d%c", &z, &ch);

    } while (z == 1);

    return (0);
}

// Function to compute FIRST set
void first(char c)
{
    int k;
    // Check if the character is not an uppercase letter
    if (!isupper(c))
        // If true, it means 'c' is a terminal, so add it to the FIRST set and increment m
        f[m++] = c;
    else
    {
        // If 'c' is an uppercase letter (non-terminal), enter this block
        for (k = 0; k < n; k++)
        {
            // Loop through all productions
            if (a[k][0] == c)
            {
                // If the first character of the production matches 'c', enter this block
                if (a[k][2] == '$' || islower(a[k][2]))
                    // If the third character of the production is '$' or a lowercase letter,
                    // add it to the FIRST set and increment m
                    f[m++] = a[k][2];
                else
                    // If the third character of the production is an uppercase letter,
                    // recursively compute the FIRST set for that non-terminal
                    first(a[k][2]);
            }
        }
    }
}

// Function to compute FOLLOW set
void follow(char c)
{
    // Check if 'c' is the start symbol
    if (a[0][0] == c)
        // If true, add '$' to the FOLLOW set and increment the index 'm'
        f[m++] = '$';

    // Iterate through all productions in the grammar
    for (i = 0; i < n; i++)
    {
        // Iterate through characters in the current production starting from the third character
        for (j = 2; j < strlen(a[i]); j++)
        {
            // Check if the current character in the production matches 'c'
            if (a[i][j] == c)
            {
                // If true, and there is a character after 'c' in the production, call the 'first' function for that character
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);

                // If the next character is the end of the production and 'c' is not the leftmost symbol in the production,
                // call the 'follow' function for the leftmost symbol of the production
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
