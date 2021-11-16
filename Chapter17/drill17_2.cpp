#include "../header.h"

void print_array(ostream& os, int* a, int n)
{
	 for (int i=0; i<n; i++)
		 os << a[i] << " ";
	cout<<"\n";
}

void print_vector(vector<int>& v)
{
	for (int i=0; i<10; i++)
		cout << v[i] << " ";
	cout<<"\n";
}

int main()
try{
	//1,2
	int a = 7;
	int* p1 = &a;
	cout<<"p1:"<<p1<<" a:"<<a<<"\n";
	//3,4
	int* array=new int[7]{1,2,4,8,16,32,64};
	int* p2 = array;
	cout<<"p2:"<<p2<<"\n";
	cout<<"array elements:\n";
	print_array(cout,array,7);
	//5,6,7,8
	int* p3 = p2;
	p1=p2;
	p2=p3;
	cout<<"p1:"<<p1<<" p2:"<<p2<<" p3:"<<p3<<"\n";
	cout<<"p1:"<<p1<<" points to array: \n";
	print_array(cout,array,7);
	cout<<"p2:"<<p2<<" points to array: \n";
	print_array(cout,array,7);
	//9.
	delete[] array;

	//10,11,12
	int* array2=new int[10]{1,2,4,8,16,32,64,128,256,512};
	p1 = array2;
	cout<<"10 size arrays:\n";
	print_array(cout,array2,10);

	int* array3=new int[10];
	p2= array3;
	print_array(cout,array3,10);

	for (int i = 0; i < 10; ++i)
	 	array3[i]=array2[i];

	cout<<"Copied array:\n";
	print_array(cout,array3,10);

	delete[] array2;
	delete[] array3;

	cout<<"10 size vectors:\n";
	vector <int> vector1{1,2,4,8,16,32,64,128,256,512};
	print_vector(vector1);
	vector <int> vector2(10);
	print_vector(vector2);
	for (int i = 0; i < vector1.size(); ++i)
	 	vector2[i]=vector1[i];

	cout<<"Copied vector:\n";
	print_vector(vector2); 
}
catch (exception& e) {
    cerr << "exception: " << e.what() <<"\n";
}
catch (...) {
    cerr << "Something went wrong. \n";
}
