#include "./header.h"

int main()
{
	cout << "Enter your name and age:";
	string firstname;
	string lastname;
	int age;

	cin >> firstname >>lastname >> age;
	string name = firstname+" "+lastname;
	cout << "Hello," <<name <<" age is:" <<age <<"\n";
	return 0;
}