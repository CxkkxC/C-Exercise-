#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
/*	char *name[] = {"手电筒","电池"};
	double price[] = {75.825,4.1};
	int n;
	cout<<"商品名称 单价\n"<<setiosflags(ios::left);
	for(n = 0;n<2;n++)
	{
		cout<<setw(8)<<name[n]; cout<<" ";
		cout<<setw(6)<<price[n]; cout<<endl;
	}
	ofstream fout;
	fout.open("price.txt");
	fout<<"商品名称 单价\n"<<setiosflags(ios::left);
	for(n=0;n<2;n++)
	{
	fout<<setw(8)<<name[n]; fout<<" ";
	fout<<setw(6)<<price[n];  fout<<endl;
	}
	fout.close();
	*/
	char name[20];
	double price;
	ifstream fin;
	fin.open("price.txt");
	fin.getline(name,19);
	cout<<name<<endl;
	for(int n=0;n<2;n++)
	{
	fin>>name>>price;
	cout<<name<<","<<price<<endl;
	}
	fin.close();
	return 0;
}
