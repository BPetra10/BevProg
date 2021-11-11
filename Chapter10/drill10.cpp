#include "../header.h"

//1.
struct Point
{
	int x;
	int y;
};

void PrintDatas(string vectorName,vector<Point> vector)
{
	cout<<vectorName<<"'s datas:\n";
	for(const auto& points:vector)
		cout<<"("<<points.x<<","<<points.y<<")"<<"\n";
}

int main()
try{
	//2.
	cout<<"Please give 7 (x,y) pair: \n";
	char first,last,comma;
	int firstNumber, secondNumber;
	vector<Point> original_points;

	while(original_points.size()!=7)
	{
		cin>>first>>firstNumber>>comma>>secondNumber>>last;
		if(first!='(')
			error("Your first character has to be (. \n");
		if(!int(firstNumber))
			error("The given value is not a number. \n");
		if(comma!=',')
			error("You forgot the comma. \n");
		if(!int(secondNumber))
			error("The given value is not a number. \n");
		if(last!=')')
			error("Your last character has to be ). \n");

		Point p;
		if(first=='(' && int(firstNumber) && comma==',' && int(secondNumber) && last==')')
		{
			p.x=firstNumber;
			p.y=secondNumber; 
			original_points.push_back(p);
		}
	}

	//3.
	PrintDatas("original_points",original_points);

	//4.
	string outPutName="mydata.txt";
	ofstream ofile {outPutName};
	if(!ofile) error("Can't open ofile ",outPutName);
	for(const auto& points:original_points)
		ofile<<"("<<points.x<<","<<points.y<<")"<<"\n";
	ofile.close();

	//5.
	string inPutName=outPutName;
	ifstream ifile {inPutName};
	if(!ifile) error("Can't open ifile ",inPutName);
	vector<Point> processed_points;

	Point p;
	while(ifile>>first>>firstNumber>>comma>>secondNumber>>last)
	{
		p.x=firstNumber;
		p.y=secondNumber; 
		processed_points.push_back(p);
	}
	ifile.close();

	//6.
	cout<<"Both vector elements: \n";
	PrintDatas("original_points",original_points);
	PrintDatas("processed_points",processed_points);

	//7.
	if (original_points.size() != processed_points.size())
        cout << "Something's wrong!\n";

	return 0;
}
catch(exception& e)
{
    cerr <<e.what()<<"\n";
    return 1;
}
catch (...) {
    cerr << "Something terrible happened!\n";
    return 2;
}