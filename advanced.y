%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UNIMUS
%%
L:E'\n' {printf("Result is %d",$1);}
;
E:E'+'E {$$=$1+$3;}
E:E'-'E {$$=$1-$3;}
E:E'*'E {$$=$1*$3;}
E:E'/'E {$$=$1/$3;}
|'('E')' {$$=$2;}
|'-'E %prec UNIMUS
|NUMBER {$$=$1;}
%%
void main(){
	printf("Enter the Expression:");
	yyparse();
	}
yylex()
	{
	char ch;
	ch=getchar();
		if(isdigit(ch))
		{
		ungetc(ch,stdin);
		scanf("%d",&yylval);
		return NUMBER;
		}
		else
			return ch;
	}
yyerror()
	{
	printf("Invalid Operation");
	exit(0);
	} 
