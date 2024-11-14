#include<iostream>
using namespace std;
int main()
{
int rows, col;


cout<<"enter rows:";
cin>>rows;
cout<<"enter coulumns:";
cin>>col;
int arry[rows][col];

//input elemnts
int elements;
cout<<"enter the elements";

for(int i=0; i<rows; i++)
{
	for(int j=0; j<col; j++)
	{
		cout<<"\nelements["<<i<<"]["<<j<<"]:";
		cin>>arry[i][j];	}
	
}
cout<<"\n the 2D array is:\n";
for(int i=0; i <rows; i++)
{
	for(int j=0; j<col; j++)
	{
		cout<<arry[i][j]<< " " ;
	}
}
cout<<endl;
return 0;
}