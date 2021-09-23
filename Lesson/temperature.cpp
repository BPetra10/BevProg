#include "../header.h"

int main()
{
	vector<double> temps;
	cout<<"Give some numbers:\n";
	for (double temp; cin>> temp;)
		temps.push_back(temp);

	for(auto temp : temps)
		cout<<temp<<"\n";

	double sum = 0;

	for (auto temp: temps)
		sum += temp;

	cout<<"Avarage temps:"<<sum/temps.size()<<"\n";

	//Medián: Értékek sorbarendezése, és a közéső elem megadása
	sort(temps); // Vektor sorbarendezése
	
	cout<<"Increasing numbers: \n";
	for(auto temp : temps)
		cout<<temp<<"\n";

	cout << "Median of temps: "<<temps[temps.size()/2]<<"\n";

	return 0;
}