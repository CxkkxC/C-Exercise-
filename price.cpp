#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
/*	char *name[] = {"�ֵ�Ͳ","���"};
	double price[] = {75.825,4.1};
	int n;
	cout<<"��Ʒ���� ����\n"<<setiosflags(ios::left);
	for(n = 0;n<2;n++)
	{
		cout<<setw(8)<<name[n]; cout<<" ";
		cout<<setw(6)<<price[n]; cout<<endl;
	}
	ofstream fout;
	fout.open("price.txt");
	fout<<"��Ʒ���� ����\n"<<setiosflags(ios::left);
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
