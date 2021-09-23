#include "../header.h"

int main()
{
	vector<string> words;
	for (string word; cin >> word;)
		words.push_back(word);

	cout<<"Number of words: "<<words.size()<<"\n";

	sort(words);//unicode alapján sortol
	for (string word: words)
	{
		cout<<word<<"\n"; //innen a q helyett a ctrl+d-vel lehet kilépni windowson ctrl+z
	}

	return 0;
}