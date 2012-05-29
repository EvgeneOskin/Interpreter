#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int abs(int N)
{
	if (N >= 0)
		return N;
	else 
		return -N;
}
void printf_word(char *array)
{
	int i=0;
	for (i=0; array[i] != '\0'; i++)
		cout << array[i];
	return;
}

void analize (char *str, int size_str)
{
	int i, j=0, k=0, size_vars=0, max_var_name=0,
		var_name=0, brackets_amount=0, brackets_j=0,
		brackets_k=0, opperations_j=0,
		printf_i=0;
	cout << "\nyour string	its size is %i\n";
	for (i=0; i < size_str; i++)
	{	
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
		{
			if (var_name > max_var_name)
				max_var_name=var_name;
			size_vars++;	
			var_name=0;
			cout << endl;
		}
		else 
			if ((str[i] != ')') && (str[i] != '('))
			{
				var_name++;
				cout << str[i];
			}
			else 
			{
				brackets_amount++;
			}
	}
	if (var_name > max_var_name)
		max_var_name=var_name;
	cout << endl << "your vars	its max size is " << max_var_name << endl;
	char vars[size_vars][max_var_name],
		opperations[size_vars];
	int brackets[brackets_amount];
	for (i=0; i < size_str; i++)
	{	
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
		{	
			vars[j][k]='\0';
			j++;
			cout << endl;
			brackets_k++;
			opperations[opperations_j++]=str[i];
		}
		else 
		{	
			if ((str[i] != ')') && (str[i] != '('))
			{	
				vars[j][k++]=str[i];
				cout << vars[j][k-1];
			}
			else
			{	
				if (str[i] == '(')
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
	cout << endl << "bracket:" << endl;
	for (i=0; i < brackets_amount; i++)
	{	
		cout << brackets[i];
	}
	cout << endl << "operations:" << endl;
	for (i=0; i < size_vars; i++)
		cout << opperations[i] << endl;
	j=0;
	k=0;
	int n=0;
	char producter[max_var_name];
	for (i=0; i < brackets_amount; i++)
	{
		k+=abs(brackets[i]);
		if (k != size_vars)
		{
			if (k == 0)
				continue;
			else
			{
				while (n < k-1)
				{
					for (printf_i=0; vars[n][printf_i] != '\0'; printf_i++)
					{
						cout << vars[n][printf_i];
					}
					cout << opperations[n];
					n++;
				}
				if ((opperations[k-1] == '*') && (brackets[i]>0))//test for "a+a*(b+c)"
				{
					cout << '(';
					for( printf_i=0; vars[n][printf_i] != '\0'; printf_i++)
					{
						cout << printf_i;
						cout << vars[k-1][printf_i];
					}
					cout << '*';
					j=1;
					n=0;
					while (j < abs(brackets[i+1])+1)
					{
					
						for (printf_i=0; vars[k+j][printf_i] != '\0'; printf_i++)
							cout << vars[k+j][printf_i];
						if (j < abs(brackets[i+1]))
							cout << opperations[k-1+j];
						cout << j;
						j++;
						if ((opperations[k-2+j] == '+') && (opperations[k-2+j] == '-'))
						{
							for(printf_i=0; vars[k-1][printf_i] != '\0'; printf_i++)
								cout << vars[k-1][printf_i];
							cout << '*';
						}
					}
					j++;
					for (printf_i=0; vars[k+j][printf_i] != '\0'; printf_i++)
						cout << vars[k+j][printf_i];
					cout << ')';
				}
			}
		}
		else
		{
			break;
		}
	}
	return;
}

int main()
{
	char str[1000];
	int i=0, error_INDEX=0, size_str, braket_INDEX=0;
	cout << "input your string\n";
	ifstream inf("input.dat", ios::in);
	if (!inf)
	{
		cout << "Can't open file!\n";
	}
	while (inf)
	{
		inf.get(str[i]);
		if(inf) cout << str[i];
		i++;
	}
	for (i=0; str[i] != '\0'; i++)
		cout << str[i];
	cout << endl;
	str[i]='\0';
	size_str=i;
	if ((str[0] == '+') || (str[0] == '-') || (str[0] == '/') || (str[0] == '*') || (str[0] == ')') || (str[0] == '.'))
	{	
		error_INDEX++;
		cout << "i don't understand you" << endl; 
	}
	for (i=0; i<size_str; i++)
	{
		if (str[i] == '(')	
			braket_INDEX++;
		else	
			if (str[i] == ')')	
				if(--braket_INDEX<0)
				{
					cout << "braket error in coloumn "<< i-1 << endl; 
					error_INDEX++;
					break;
				}
		if (((str[i] == '+') || (str[i] == '-') || (str[i] == '/') || (str[i] == '*') || (str[i] == '.')) && (str[i-1] == str[i]) && (i != 0))
		{	
			cout << "too much operations in coloumn " << i-1 << endl; 
			error_INDEX++;
			break;
		}
	}
	if (braket_INDEX != 0)	
	{
		cout << "braket error in coloumn " << i-1 << endl;
		error_INDEX++;	
	}
	if (error_INDEX == 0)	
		analize(str, size_str);
	inf.close();
	return 0;
}
