%{
#include<stdio.h>
int space=0, word=0, line=0, count=0;
%}

%%
[\n] { line++;}
[ \t] { space++;}
[^\t\n ]+ { word++;count+=yyleng;}
%%

int main(){
	printf("Enter the Input: ");
	yylex();
	printf("Number of lines : %d\n",line);
	printf("Number of spaces : %d\n",space);
	printf("Number of words : %d\n",word);
	printf("Number of characters: %d\n",count);
}

int yywrap( )
{
    return 1;
}