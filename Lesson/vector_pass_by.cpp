#include "../header.h"

void print_vector(vector<double>& v){
	cout<<"(";
	//for (auto elem:v)
	//cout<<elem<<",";
	cout<<"\n";
}

int main()
{
	int x = numeric_limits<int>::max();
	vector<double> vk(x);
	print_vector(vk);
}