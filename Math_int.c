#include "stdio.h"

void analize(char* str,int size_str)
{
	int i,j=0,k=0,size_vars=0,max_var_name=0,var_name=0,brackets_amount=0,opperations_amount=0,brackets_j=0,brackets_k=0,opperations_j=0,opperations_k=0;
	printf("\nyour string	its size is %i\n",size_str);
	for(i=0;i<size_str;i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
			{	
				if(var_name>max_var_name)
					max_var_name=var_name;
				size_vars++;	var_name=0;
				printf("\n");
			}
		else 
			if(str[i]!=')'&&str[i]!='(')
			{	
				var_name++;
				printf("%c",str[i]);
			}
			else 
				{
					brackets_amount++;
				}
	}
	if(var_name>max_var_name)
	max_var_name=var_name;
	opperations_amount=size_vars-1;
	printf("\nyour vars\n%i\n",max_var_name);
	char vars[size_vars][max_var_name];
	int brackets[brackets_amount],opperations[opperations_amount];
	for(i=0;i<size_str;i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			vars[j][k]=NULL;
			j++;
			printf("\n");
			brackets_k++;
			opperations_k++;
			if(str[i]=='+')	opperations[opperations_j++]=2*opperations_k+1;
			if(str[i]=='-')	opperations[opperations_j++]=-(2*opperations_k+1);
			if(str[i]=='*')	opperations[opperations_j++]=2*opperations_k;
			if(str[i]=='/')	opperations[opperations_j++]=-2*opperations_k;
		}
		else 
			{
				if(str[i]!=')'&&str[i]!='(')
				{
					vars[j][k++]=str[i];
					printf("%c",vars[j][k-1]);
				}
				else
				{
					if(str[i]=='(')
					{
						brackets[brackets_j++]=brackets_k;
						brackets_k=0;
					}
					else	
					{
						brackets[brackets_j++]=-brackets_k;
						brackets_k=0;
					}
				}
			}
	}
		printf("\nbracket\n");
		for(i=0;i<brackets_amount;i++)
		{	
			printf("%i\n",brackets[i]);
			getchar();
		}
		printf("\noperations\n");
		for(i=0;i<opperations_amount;i++)
		printf("%i\n",opperations[i]);
	getchar();
	return;
}

int main()
{
	char str[1000];
	int i=-1,error_INDEX=0,size_str,braket_INDEX=0;
	printf("input your string\n");
	do
	{
		scanf("%c",&str[++i]);
		
	}
	while(str[i]!='\n');
	str[i]=NULL;
	size_str=i;
	if(str[0]=='+'||str[0]=='-'||str[0]=='/'||str[0]=='*'||str[0]==')'||str[0]=='.')
	{
		error_INDEX++;
		printf("i don't understand you\n"); 
	};
	for(i=0;i<size_str;i++)
	{
		if(str[i]=='(')		braket_INDEX++;
		else	
			if(str[i]==')')	
				if(--braket_INDEX<0)
				{
					printf("braket error in coloumn %i",i-1); error_INDEX++;
					break;
				}
		if((str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='.')&&str[i-1]==str[i]&&i!=0)
			{
				printf("too much operations in coloumn %i",i-1); error_INDEX++;
				break;
			}
	}
	if(braket_INDEX!=0)	
	{
		printf("braket error in coloumn %i",i-1);	 error_INDEX++;
	}
	if (error_INDEX==0)	analize(str,size_str);
	getchar();
	return;
}
