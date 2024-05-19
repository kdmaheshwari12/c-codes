#include<iostream>
using namespace std;
int Add(int num1 , int num2){
	return num1+num2;
}
int Subtract(int num1 , int num2){
	return num1-num2;
}
int Multiply(int num1 , int num2){
	return num1*num2;
}
float Divide(float num1 , float num2){
	return num1/num2;
}
int main(){
	int opt, num1,num2;
	
	while(1){
		cout<<endl;
		cout<<"Select the Operation: \n 1- Add \n 2- Subtract \n 3- Multiply \n 4- Divide \n 5- Exit"<<endl;
		cin>>opt;
	
		switch(opt){
			case 1:
				cout<<"Enter the num1: ";
				cin>>num1;
				cout<<"Enter the num1: ";
				cin>>num2;
				
				cout<<"Ans: "<<Add(num1,num2)<<endl;
				break;
				
			case 2:
				cout<<"Enter the num1: ";
				cin>>num1;
				cout<<"Enter the num1: ";
				cin>>num2;
				
				cout<<"Ans: "<<Subtract(num1,num2)<<endl;
				break;
			
			case 3:
				cout<<"Enter the num1: ";
				cin>>num1;
				cout<<"Enter the num1: ";
				cin>>num2;
				
				cout<<"Ans: "<<Multiply(num1,num2)<<endl;
				break;
			
			case 4:
				cout<<"Enter the num1: ";
				cin>>num1;
				cout<<"Enter the num1: ";
				cin>>num2;
				
				cout<<"Ans: "<<Divide(num1,num2)<<endl;
				break;
				
			case 5:
				return 0;
				break;
		}
	}
}
