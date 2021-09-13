#include "../header.h"

int main(){
	//1.
	cout << "Enter your first name:";
	string firstName;
	cin >> firstName;
	cout << "Hello " << firstName<<"\n";
	cout << "Enter the name of the person you want to write to:";
	string modifyFirstName;
	cin >> modifyFirstName;
	cout << "\t Dear " << modifyFirstName <<",\n";
	//2.
	cout << "How are you? I'm fine. I miss you.\n" 
	<<"What did you do in the summer camp? \n Where were you?\n";
	//3.
	cout << "Add another friend name:";
	string anotherFriend;
	cin>> anotherFriend;
	cout << "Have you seen "<<anotherFriend<<" lately?\n";
	//4.
	char friendSex = '0';
	cout << "Enter an m, if your friend is a male, f if female:";
	cin>> friendSex;
	if (friendSex=='m')
	{
		cout << "If you see "<<anotherFriend<<" please ask him to call me.\n";
	}
	else if(friendSex=='f')
	{
		cout << "If you see "<<anotherFriend<<" please ask her to call me.\n";
	}
	else
	{
		cout << "If you see "<<anotherFriend<<" please ask them to call me.\n";
	}
	//5.
	cout << "Please enter an age: ";
	int age;
	cin>>age;
	if(age<=0 || age<=110)
	{
		simple_error("You are kidding!");
	}else
	{
		cout<<"I hear you just had a birthday and you are "<<age<<" years old.\n";
	}
	return 0;
}
