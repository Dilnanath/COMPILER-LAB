%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER
%%
L:E'\n' {printf("%d",$1);}
;
E:E'+'T {$$=$1+$3;}
|T {$$=$1;}
;
T:T'*'F {$$=$1*$3;}
|F {$$=$1;}
;
F:NUMBER {$$=$1;}
;
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
