#include "../header.h"

int main()
{
	vector<int> v = {1,2,3,4,5};

	for (int i = 0; i < v.size(); ++i) //v.size() a vektor elemszámát adja meg
	{
		cout<< v[i] << "\n";
	}

	vector<string> philosophers = {"Kant","Platon","Hume"};

	for (string name: philosophers) //range for loop C#-ban ez foreach
		cout << name << "\n";

	vector <double> dv;
	cout<< "dv vector size: "<<dv.size()<<"\n";
	dv.push_back(0);
	dv.push_back(1);
	dv.push_back(25.6);
	cout<< "dv vector size now: "<<dv.size()<<"\n";

	for (double value: dv) //autómatikus típusfelismerés: for (auto value: dv)
		cout << value << "\n";

	return 0;
}