#include<stdio.h>
#include<ctype.h>


int top=-1,sl=1;
char stack[100];
char infix[100],postfix[100];
void postfix_con();
int prec(char ch);

int main()
{
	printf("enter the expression:");
	scanf("%s",infix);
	postfix_con();

	int i=0,add=2000;
	
	printf("enter the starting address:");
	scanf("%d",&add);
	
	while(postfix[i]!='\0')
	{
		char ch=postfix[i];
		i++;
		if(isalpha(ch))
		{
			printf("%d\tMOVE\tA,%c\n",add,ch);
			add++;
			printf("%d\tPUSH\tA\n",add);
			add++;
		}
		else
		{
			printf("%d\tPOP\tA\n",add);
			add++;
			printf("%d\tPOP\tB\n",add);
			add++;
			switch(ch)
			{
				case '+':
					printf("%d\tADD\tB\n",add++);
					printf("%d\tPUSH\tA\n",add++);
					break;
			
				case '-':
					printf("%d\tSUB\tB\n",add++);
					printf("%d\tPUSH\tA\n",add++);
					break;
				
				case '*':
					printf("%d\tMUL\tB\n",add++);
					printf("%d\tPUSH\tA\n",add++);
					break;
					
				case '/':
					printf("%d\tDIV\tB\n",add++);
					printf("%d\tPUSH\tA\n",add++);
					break;		
			}
		}
		
	}
	printf("%d\tHALT\n",add);
	return 0;
}


void postfix_con()
{
	int j=0;
	int i=0;
	while(infix[i]!='\0')
	{
		char ch=infix[i];
		if(isalpha(ch)){
		postfix[j++]=ch;
	
		}
		else if(ch=='(')
		{
			stack[++top]=ch;
		}
		else if(ch==')')
		{
			while(stack[top]!='(')
			{
				postfix[j++]=stack[top--];
			}
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
			while(prec(ch)<=prec(stack[top]))
			{
				postfix[j++]=stack[top--];
			}
			stack[++top]=ch;
		}
		else printf("error\n");
		i++;
	}
	if(top!=-1)
	{
		while(top!=-1)
		{
			postfix[j++]=stack[top--];
		}
	}
	postfix[j]='\0';
}

int prec(char ch)
{
	if(ch=='+'||ch=='-') return 2;
	else if(ch=='*'||ch=='/') return 3;
	else return 1;
}

