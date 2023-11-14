%{
int COMMENT=0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int | float | char | double | while | for | struct | typedef | 
do | if |break | continue | void | switch |  return | else | goto {printf("\n%s\t is a keyword",yytext);}
"/*" {COMMENT=1;}{printf("\n %s\t is a COMMENT",yytext);}
{identifier}\( {if(!COMMENT)printf("\n%s\t\tFUNCTION ",yytext);}
\{ {if(!COMMENT)printf("\n %s\t IS BLOCK BEGINS",yytext);}
\} {if(!COMMENT)printf("\n%s\t IS BLOCK ENDS ",yytext);}
\; {if(!COMMENT)printf("\n%s\t PUNCTUATOR ",yytext);}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s\t IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n%s\t is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n%s\t is a NUMBER ",yytext);}
\)(\:)? {if(!COMMENT)printf("\n\t");ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT)printf("\n %s\t is an ASSIGNMENT OPERATOR",yytext);}
\<= | \>= | \< | == | \> {if(!COMMENT) printf("\n%s\t is a RELATIONAL OPERATOR",yytext);}

%%
int main(int argc, char **argv){
    FILE *file;
    file=fopen("input.c","r");
    if(!file){
        printf("could not open the file");
        exit(0);
    }
    yyin=file;
    yylex();
    printf("\n");
    return(0);
}
int yywrap(){
    return(1);
}
