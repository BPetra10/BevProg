#include "../header.h"

int main(){
	string previous="";
	string current;
	while(cin>>current)
	{
		if(current==previous)
			cout<<"Repeating word: "<<current<<"\n";
		previous=current;
	}
	return 0;
}