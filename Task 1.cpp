#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(static_cast<unsigned int>(time(NULL)));
	int randnum;
	
	randnum=rand()%100+1;

	int userguess=0;
	while(userguess!=randnum){
		cout<<"Enter the number :";
		cin>>userguess;
		
		if(userguess<randnum){
			cout<<"too Low try again "<<endl;
		}
		else if(userguess>randnum){
			cout<<"too High try again"<<endl;
		}
		else{
			cout<<"Correct number Congratulations"<<endl;	
		}
	}
}
