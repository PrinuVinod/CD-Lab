%{
#include<stdio.h>
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'

%%
stmp: exp {
              printf("\nResult=%d\n",$1); 
	      return 0;
	     }
exp : 	exp '+' exp { $$ = $1 + $3; }
	| exp '-' exp { $$ = $1 - $3; }
	| exp '*' exp { $$ = $1 * $3; }
	| exp '/' exp {
		      if($3==0)
		      {
		      	printf("\nDivision not possible");
		      	return 0;;
	      	      }
	      	      else
	      	      {
	      	      	$$ = $1 / $3;
	      	      }
	      	      }
	| '(' exp ')' { $$ = $2; }
	| NUMBER { $$ = $1; }
	| ID { $$ = $1; };
%%
int main(){
	printf("\nEnter the expression: ");
	yyparse();
	return 0;
}

int yyerror(char* msg){
	printf("Expression is invalid\n");
	return 0;
}
