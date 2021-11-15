#include "../header.h"

//4.
void print_array10(ostream& os, int* a)
{
	 for (int i=0; i<10; i++)
		 os << a[i] << " ";
}

//7.
void print_array(ostream& os, int* a, int n)
{
	 for (int i=0; i<n; i++)
		 os << a[i] << " ";
}

int main()
{
	//1-3.
	int* array = new int[10];
	print_array10(cout,array);
	cout<<"\n";
	delete[] array;
	//5.
	int* array2 = new int[10]{100,101,102,103,104,105,106,107,108,109};
	print_array10(cout,array2);
	cout<<"\n";
	//6.
	int* array3 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
	print_array(cout,array3,11);
	cout<<"\n";
	//8. 
	int* array4 = new int[20];
	for (int i = 0; i < 20; i++)
	{
		array4[i]=100+i;
	}
	print_array(cout,array4,20);
	//9. delete[] array2,array3,array4; Próbald ki majd(Valgrind)
	//9.
	delete[] array2;
	delete[] array3;
	delete[] array4;
	
	return 0;
}
