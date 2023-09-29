#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
char keyword[50][50] = {"void", "int","break", "char", "case", "const", "continue", "default", "do", "double", "else", "enum", "extern"};

int main()
{
    FILE* ptr;
	char ch, str[50];
    int i, j, n;

	ptr = fopen("test.txt", "r");

	if (NULL == ptr) 
    {
		printf("file can't be opened \n");
	}
    while (!feof(ptr)) {
        fgets(str, 50, ptr);
        int a = strcmp(keyword[i], str);
        if(a==0)
        {
            for(i=0; i<n; i++)
            {
                printf("%d", str[i]);
            }
        }
    }
    fclose(ptr);
	return 0;
}