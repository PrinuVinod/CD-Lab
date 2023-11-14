%{
	#include<stdio.h>
	int valid=1;
	
%}

%token letter digit

%%
	start:letter s;
	s:letter s|digit s|;
%%

int yyerror(){
	printf("It is not an identifier\n");
	valid=0;
	return 0;
}

int main(){
	printf("\nEnter the identifier: ");
	
	yyparse();
	if (valid){
		printf("It is an identifier\n");
	}
	return 0;
}
