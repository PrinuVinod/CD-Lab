%%
[0-9]+ {
    int num = atoi(yytext);
    printf("\n Number of digits: %d\n", (int)strlen(yytext));
    if (num % 2 == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }
}
%%

void main()
{
	extern FILE *yyin;
	yyin=fopen("eoro.txt","r");
	yylex();
}

int yywrap()
{ 
return(1);
}