#include "stdio.h"

void printf_word(char *array)
{
	int i=0;
	for(i=0;array[i]!='\0';i++)
		printf("%c",array[i]);
	return;
}

void analize(char* str,int size_str)
{
	int i,j=0,k=0,size_vars=0,max_var_name=0,
		var_name=0,brackets_amount=0,brackets_j=0,
		brackets_k=0,opperations_j=0,
		printf_i;
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
	printf("\nyour vars	its max size is %i\n",max_var_name);
	char vars[size_vars][max_var_name],opperations[size_vars];
	int brackets[brackets_amount];
	for(i=0;i<size_str;i++)
	{	if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{	
			vars[j][k]='\0';
			j++;
			printf("\n");
			brackets_k++;
			opperations[opperations_j++]=str[i];
		}
		else 
		{	
			if(str[i]!=')'&&str[i]!='(')
			{	
				vars[j][k++]=str[i];
				printf("%c",vars[j][k-1]);}
			else
			{	
				if(str[i]=='(')
				{	
					brackets[brackets_j++]=brackets_k;
					brackets_k=0;}
				else	
				{	
					brackets[brackets_j++]=-brackets_k;
					brackets_k=0;
				}
			}
		}
	}
	printf("\nbracket:\n");
	for(i=0;i<brackets_amount;i++)
	{	
		printf("%i	",brackets[i]);
	}
	printf("\noperations:\n");
	for(i=0;i<size_vars;i++)
		printf("%c\n",opperations[i]);
	j=0;
	k=0;
	int n=0;
	char producter[max_var_name];
	for(i=0;i<brackets_amount;i++)
	{
		k+=abs(brackets[i]);
		if(k!=size_vars)
		{
			if(k==0)
				continue;
			else
			{
				while(n<k-1)
				{
					for(printf_i=0;vars[n][printf_i]!='\0';printf_i++)
					{
						printf("%c",vars[n][printf_i]);
					}
					printf("%c",opperations[n]);
					n++;
				}
				if((opperations[k-1]=='*')&&(brackets[i]>0))//test for "a+a*(b+c)"
				{
					printf("(");
					for(printf_i=0;vars[n][printf_i]!='\0';printf_i++)
					{
						printf("%i",printf_i);
						printf("%c",vars[k-1][printf_i]);
					}
					printf("*");
					j=1;
					while(j<abs(brackets[i+1]))
					{
						if(opperations[k-1+j]=='+'&&opperations[k-1+j]=='-')
						{
							printf("%c",opperations[k-1+j]);
							for(printf_i=0;vars[k-1][printf_i]!='\0';printf_i++)
								printf("%c",vars[k-1][printf_i]);
							printf("*");
						}
						else
						{
							for(printf_i=0;vars[k+j][printf_i]!='\0';printf_i++)
								printf("%c",vars[k+j][printf_i]);
							printf("%c",opperations[k-1+j]);
						};
						j++;
					printf(")");
					}
				}
			}
		}
		else
		{
			break;
		}
	}
		
	getchar();
	return;
}

int main()
{
	char str[1000];
	int i=-1,error_INDEX=0,size_str,braket_INDEX=0;
	printf("input your string\n");
//	do
//	{
//		scanf("%c",&str[++i]);
//	}
//	while(str[i]!='\n');
	FILE* in;
	in=fopen("input.dat","r");
	fgets(str,sizeof(str),in);
	for(i=0;str[i]!='\0';i++)
		printf("%c",str[i]);
	printf("\n");
	str[i]='\0';
	size_str=i;
	if(str[0]=='+'||str[0]=='-'||str[0]=='/'||str[0]=='*'||str[0]==')'||str[0]=='.')
	{	
		error_INDEX++;
		printf("i don't understand you\n"); 
	}
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
		printf("braket error in coloumn %i",i-1);
		error_INDEX++;	
	}
	if (error_INDEX==0)	
		analize(str,size_str);
	getchar();
	return;
}
