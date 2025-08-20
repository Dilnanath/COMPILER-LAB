#include<stdio.h>

int j=0;
char input[20];

int E();
int E1();
int T();
int T1();
int F();

int main()
{
	printf("enter the input string: ");
	scanf("%s",input);//i+i*i
	if(E()==1 && input[j]=='\0')
	{
		printf("Accepted\n");
	}
	else{
		printf("Rejected\n");
	}
}

int E()
{
	printf("Expanding E-->TE1\n");
	if(T()==1)
	{
		if(E1()==1)
			return 1;
		else return 0;	
	}else return 0;
}

int T()
{
	printf("Expanding T-->FT1\n");
	if(F()==1)
	{
		if(T1()==1)
			return 1;
		else return 0;	
	}else return 0;
}

int E1()
{
	if(input[j]=='+')
	{
		printf("Expanding E1-->+TE1\n");
		printf("consuming +\n");
		j++;
		
		if(T()==1)
		{
			if(E1()==1)
				return 1;
			else return 0;	
		}else return 0;
	}else return 1;
}

int T1()
{
	if(input[j]=='*')
	{
		printf("Expanding T1-->*FT1\n");
		printf("consuming *\n");
		j++;
		
		if(F()==1)
		{
			if(T1()==1)
				return 1;
			else return 0;	
		}else return 0;
	}else return 1;
}

int F()
{
	if(input[j]=='(')
	{
		printf("Expanding F-->(E)\n");
		printf("consuming (\n");
		j++;
		
		if(E()==1)
		{
			if(input[j]==')')
			{
				printf("consuming )\n");
				j++;
				return 1;
			}else return 0;
		}else return 0;
	}else if(input[j]=='i')
	{
		printf("Expanding F-->i\n");
		printf("consuming i\n");
		j++;
		return 1;
	}else return 0;
}
