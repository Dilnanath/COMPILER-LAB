%{
#include<stdio.h>
#include<stdlib.h>
%}
%token LETTER DIGIT
%%
L:A'\n' {printf("Valid operation");exit(0);}
;
A:LETTER B 
|LETTER
;
B:LETTER B
|DIGIT B
|LETTER 
|DIGIT
%%
void main(){
	printf("Enter the Variable:");
	yyparse();
	}
yylex()
	{
	char ch;
	ch=getchar();
		if(isalpha(ch))
			{
			return LETTER;
			}
		else if(isdigit(ch))
			{
			return DIGIT;
			}
		else
		return ch;
	}
yyerror()
	{
	printf("Invalid Operation");
	exit(0);
	} 
