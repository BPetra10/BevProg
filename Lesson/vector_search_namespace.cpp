#include "../header.h"

namespace unideb{
int my_find(const vector<string>& vs, const string& s);
int my_find(const vector<string>& vs, const string& s, int hint);
}

namespace bme{
int my_find(const vector<string>& vs, const string& s);
int my_find(const vector<string>& vs, const string& s, int hint);
}

int main(){

	vector<string> fruits={"apple","pear","grapes","lemon","watermelon"};
	
	string s = "grapes";
	int hint = 2;

	int index = unideb::my_find(fruits,s,hint); //namespacebőli függvény meghívása namespace::fuggveny

	if (index<0)
		cout<<"fruit not found. \n";
	else
		cout<<"fruit found at: "<<index<<"\n";

	return 0;
}

namespace unideb{
int my_find(const vector<string>& vs, const string& s){
	for (int i = 0; i < vs.size(); ++i)
		if(vs[i]==s)
			return i;
	return -1;
}

int my_find(const vector<string>& vs, const string& s, int hint){
	
	if(hint<0 || vs.size()<=hint) hint=0;

	for (int i = hint; i < vs.size(); ++i)
		if(vs[i]==s) return i;

	if(0<hint)
		for (int i = 0; i < hint; ++i)
			if(vs[i]==s) return i;

	return -1;
}
}
//End of unideb 

namespace bme{
int my_find(const vector<string>& vs, const string& s){
	for (int i = 0; i < vs.size(); ++i)
		if(vs[i]==s)
			return i;
	return -1;
}

int my_find(const vector<string>& vs, const string& s, int hint){
	
	if(hint<0 || vs.size()<=hint) hint=0;

	for (int i = hint; i < vs.size(); ++i)
		if(vs[i]==s) return i;

	if(0<hint)
		for (int i = 0; i < hint; ++i)
			if(vs[i]==s) return i;

	return -1;
}
}
//End of bme 