#include<iostream>
using namespace std;
int main(){
	
	int n;                 
	long factorial= 1.0;
	
	cout<<"enter a number ";
	cin>>n;
	if(n<0)
	cout<<"INVALID";
	else{
		for(int i=1;i<=n;i++){
	
		factorial*=i;}
		cout<<"fact of "<<n<<"="<<factorial;
	
	}
	return 0;
}
