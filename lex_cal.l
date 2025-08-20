%{
	#include<stdio.h>
	#include<math.h>
	int flag=0;
	int a;
%}

DIGIT [0-9]

%%

"+" {flag=1;}
"-" {flag=2;}
"*" {flag=3;}
"/" {flag=4;}
"^" {flag=5;}
{DIGIT}+ {if(flag==0) a=atoi(yytext);
			else if(flag==1) a+=atoi(yytext);
			else if(flag==2) a-=atoi(yytext);
			else if(flag==3) a*=atoi(yytext);
			else if(flag==4) a/=atoi(yytext);
			//else if(flag==5) a=power(a,atoi(yytext));
			else;}
			
"\n" {printf("the result = %d\n",a);}
. {printf("unrecognized symbol %s\n",yytext);}			

%%
void main(int argc,char *argv[])
{
	printf("enter:");
	yyin=stdin;
	yylex();
}
int yywrap()
{
	return 1;
}

