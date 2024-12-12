#include<iostream>
#include<fstream>//header file
using namespace std;
int main()
{
		//creating a file
	ofstream file("newfile.txt") ; 
	
     file<<"hello my name is ayesha";
     file.close();
	
	string Text;

	ifstream readfile("newfile.txt");
	while	(getline(readfile,Text))
{
	cout<<Text;
	}	
	readfile.close();
	
	return 0;
}