#include "../header.h"

struct Reading{
int hour;
double temperature;
};

int main()
try{
	cout<<"Please enter input file name:";
	string ifname;
	cin>>ifname;
	ifstream ifile {ifname};
	if(!ifile) error("Can't open ifile",ifname);

	vector<Reading> readings;
	int hour;
	double temp;

	while(ifile>>hour>>temp)
	{
		if(hour<0 || hour>23) error("Invalid hour.");
		readings.push_back(Reading{hour,temp});
	}
	double sum = 0;
	for (const auto& reading:readings)
	{
		sum+=reading.temperature;
	}
	cout<<"Avarage temperature: "<<sum/readings.size()<<"\n";
	cout<<"Please enter output file name:";
	string ofname;
	cin>>ofname;
	ofstream ofile {ofname};
	if(!ofile) error("Can't open ofile",ofname);

	for (const auto& reading:readings)
		ofile<<reading.hour<<" "<<reading.temperature;
	ifile.close();
	ofile.close();

	return 0;
}catch(runtime_error& e){
	cerr<<"Error: "<<e.what()<<'\n';
	return 1;
}catch(...){
	cerr<<"Some Error";
	return 2;
}