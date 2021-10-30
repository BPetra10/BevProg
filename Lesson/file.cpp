#include "../header.h"

int main()
try{
	cout<<"Please enter input file name:";
	string ifname;
	cin>>ifname;
	ifstream ifile {ifname};
	if(!ifile) error("Can't open ifile",ifname);

	cout<<"Please enter output file name:";
	string ofname;
	cin>>ofname;
	ofstream ofile {ofname};
	if(!ofile) error("Can't open ofile",ofname);

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