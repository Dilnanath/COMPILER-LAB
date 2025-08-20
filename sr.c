#include<stdio.h>
#include<string.h>
char ch;
char st[20];
int sl=2;
int j=0,top=0;
char ip[20];

void reduce()
	{
	int z=0;
	for(z=0;z<top;z++)
		{
		if (st[z]== 'i')
			{
			st[z]='E';
			printf("\n %d \t $%s \t %s$ \t reduce E-> i", sl,st,ip);
			sl++;
			}
		}
	for(z=0;z<top;z++)
		if (st[z]=='(' && st[z+1] == 'E' && st[z+2] == ')')
			{
			st[z]='E';
			st[z+1]= '\0';
			top = top-2;
			printf("\n %d \t $%s \t %s$ \t reduce E -> (E)", sl,st,ip);
			sl++;
			}	
	for(z=0;z<top;z++)
		if (st[z]=='E' && st[z+1] == '+' && st[z+2] == 'E')
			{
			st[z]='E';
			st[z+1]= '\0';
			top = top-2;
			printf("\n %d \t $%s \t %s$ \t reduce E -> E+E", sl,st,ip);
			sl++;
			}
	for(z=0;z<top;z++)
		if (st[z]=='E' && st[z+1] == '*' && st[z+2] == 'E')
			{
			st[z]='E';
			st[z+1]= '\0';
			top = top-2;
			printf("\n %d \t $%s \t %s$ \t reduce E -> E*E", sl,st,ip);
			sl++;
			}
	}
	
int main()
	{
	
	printf("Enter string :");
	scanf("%s",ip);
	
	printf("Sl no \t Stack \t Input \t\t Action");
	printf("\n 1 \t  $\t  %s \t",ip);
	
	
	
	while (ip[j] != '\0')
		{
		ch = ip[j];
		st[top++] = ch;
		st[top] = '\0';
		ip[j] = ' ';
		j++;
		printf("\n %d \t $%s \t %s$ \t shift %c", sl,st,ip,ch);
		sl++;
		reduce();
		}
	if (st[0]=='E' && st[1] == '\0') 
		printf("\nString accepted \n");
	else printf("\nString rejected \n");
	}

