%{
#include<stdio.h>
int sc=0,pc=0;
%}

%%
"printf" {fprintf(yyout,"writef");pc++;}
"scanf" {fprintf(yyout,"readf");sc++;}
%%

int main()
{
    extern FILE *yyin;
	yyin=fopen("counti.txt","r");
	yyout=fopen("counto.txt","w");
	yylex();
	printf("%d%d",pc,sc);
}

int yywrap()
{
    return 1;
}