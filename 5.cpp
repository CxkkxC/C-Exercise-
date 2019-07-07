#include<iostream>
using namespace std;
void quickSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;				// ×ó±ß
	int j = right;				// ÓÒ±ß
	int key = a[left];
	while (i < j)
	{
		while (i < j && key <= a[j])	
		{
			j--;
		}
		a[i] = a[j];			
		while (i < j && key > a[i])	
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	
	quickSort(a, left, i - 1);	
	quickSort(a, i + 1, right);
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quickSort(a,0,n-1);
	for(int j=0;j<n;j++)
		cout<<a[j]<<endl;
	delete[] a;
	return 0;
}
