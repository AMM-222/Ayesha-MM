#include<iostream>
using namespace std;


void value(int num)
{
	num= num +10;
	cout<<"inside function(Value)="<<num<<endl;
	
	
}
void mult(int num)
{
	num= num*10;
	cout<<"inside function(Value)="<<num<<endl;
}
int main()
{
	int number= 5;
	cout<<" Before function call="<<number<<endl;
	value(number);
	cout<<"Before function call="<<number<<endl;
	mult(number);
	
	return 0;
}
	