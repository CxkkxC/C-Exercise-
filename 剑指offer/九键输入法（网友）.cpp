#include<iostream>
using namespace std;
void change(int& number, int n){
	number *= 10;
	number += n;
}
int main(){
	char c;
	int num=0;
	while ((c=getchar())!='\n')
	{
		if (c >= 'a'&&c <= 'c' || c >= 'A'&&c <= 'C'){
			change(num, 2);
		}
		else if (c > 'c'&&c <= 'f' || c >'C'&&c <= 'F'){
			change(num, 3);
		}
		else if (c > 'f'&&c <= 'i' || c >'F'&&c <= 'I')
			change(num, 4);
		else if (c > 'I'&&c <= 'L' || c >'i'&&c <= 'l')
			change(num, 5);
		else if (c > 'l'&&c <= 'm' || c >'L'&&c <= 'M')
			change(num, 6);
		else if (c > 'm'&&c <= 's' || c >'M'&&c <= 'S')
			change(num, 7);
		else if (c > 's'&&c <= 'v' || c >'S'&&c <= 'V')
			change(num, 8);
		else if (c > 'v'&&c <= 'z' || c > 'V'&&c <= 'Z')
			change(num, 9);
		else
			continue;
	}
	cout << num << endl;
	return 0;
}

