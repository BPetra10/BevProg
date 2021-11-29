#include "../header.h"

//4.
void print_array10(ostream& os, int* a)
{
	 for (int i=0; i<10; i++)
		 os << a[i] << " ";
	os<<"\n";
}

//7.
void print_array(ostream& os, int* a, int n)
{
	 for (int i=0; i<n; i++)
		 os << a[i] << " ";
	os<<"\n";
}

void print_vector(vector<int>* v, int n)
{
	for (int i=0; i<n; i++)
		cout << (*v)[i]<< " ";  //dereferencia 
		cout<<"\n";
}

int main()
try{
	//1-3.
	int* array = new int[10]{100,101,102,103,104,105,106,107,108,109};
	print_array10(cout,array);
	delete[] array;
	//5.
	int* array2 = new int[10]{100,101,102,103,104,105,106,107,108,109};
	print_array10(cout,array2);
	//6.
	int* array3 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
	print_array(cout,array3,11);
	//8. 
	int* array4 = new int[20];
	for (int i = 0; i < 20; i++)
		array4[i]=100+i;

	print_array(cout,array4,20);
	//9.
	delete[] array2;
	delete[] array3;
	delete[] array4;

	//10.
	vector <int> vector1{100,101,102,103,104,105,106,107,108,109};
	vector <int>* p = &vector1;
	print_vector(p,10);

	vector <int> vector2{100,101,102,103,104,105,106,107,108,109,110};
	vector <int>* p2 = &vector2;
	print_vector(p2,11);

	vector<int> vector3;
	for (int i = 0; i < 20; i++)
		vector3.push_back(100+i);

	/*
	vector<int> vector3(20);
	for (int i = 0; i < 20; i++)
		vector3[i]=100+i;
	*/
	vector <int>* p3 = &vector3;
	print_vector(p3,20);
	
	return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() <<"\n";
}
catch (...) {
    cerr << "Something went wrong. \n";
}
