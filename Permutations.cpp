#include<iostream>
#include"Ac++\StanfordCPPLib\collections/set.h"
#include"Ac++\StanfordCPPLib\io\simpio.h"
using namespace std;

Set<string> generatePermutations(string str);

int main()
{
	string str = getLine("ÇëÊäÈëÒ»´®×Ö·û£º");
	cout<<"The permutatios of \""<<str<<"\" are:"<<endl;
	for(string s: generatePermutations(str)){
		cout<<"  \""<<s<<"\""<<endl;
	}
	return 0;
}

Set<string> generatePermutations(string str){

	}