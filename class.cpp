#include <iostream>
using namespace std;

class braket
{
	public:
		unsigned int size;
		char *opperations;
		char *elements;
		mixed_opper(opper A,opper B);
		braket();
		~braket();
}

braket::braket()
{
	
	opperations=new char [size];
	elements=new char [size];
}
braket::~braket()
{
	delete []opperations;
	delete []elements;
}

class series
{
	public:
		unsigned int size;
		char opperation;
		char *elements;
		void add_element(series &A);
		series(char IN_opperation, char* IN_elements);
		~series();
};
void series::add_element (series &A)
{
	char *new_elements;
	if(opperation == A.opperation)
	{
		new_elements = new char [size + A.size];
		if (size != 0)
		{
			for(int i = 0; i < size; i ++)
			{
				new_elements[i] = elements[i];
			}
			opperation = A.opperation;
		}
		for(int i = 0; i < A.size; i++)
		{
			new_elements[size+i] = A.elements[i];
		}
		delete []elements;
	}
	else
	{
		cout << "change your oppers or use class \"braket\"" << endl;
	}
	elements = new_elements;
}

series::~series ()
{
	delete []elements;
}//destructor

series::series (char IN_opperation, char* IN_elements)
{
	opperation=IN_opperation;
	size=0;
	for (int i=0; IN_elements[i] != '\0';i++)
	{
		size++;
	}
	elements = new char [size];
	for(int i=0; i < size; i++)
	{
		elements[i]=IN_elements[i];
	}
}//contructor
int main()
{
	cout << "I'm working" << endl;
	char str_test_1[5]="a b ";
	char str_test_2[5]="c d ";
	series test_object_1('*',str_test_1);
	series test_object_2('*',str_test_2);
	cout << "size_1= " << test_object_1.size << endl;
	cout << "opperation_1= " << test_object_1.opperation << endl;
	cout << "elements_1= "<< test_object_1.elements << "|" << endl;
	cout << "size_2= " << test_object_2.size << endl;
	cout << "opperation_2= " << test_object_2.opperation << endl;
	cout << "elements_2= "<< test_object_2.elements << "|" << endl;
	test_object_1.add_element(test_object_2);
	cout << "after add_element"<< endl;
	cout << "size= " << test_object_1.size << endl;
	cout << "opperation= " << test_object_1.opperation << endl;
	cout << "elements= "<< test_object_1.elements << "|" << endl;
}
