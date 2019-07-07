/* 
   �����㷨�ܽ� ��Selection Sort ��ѡ������) ��Merge
   Sort���鲢���� ��Quick Sort���������� ��Bubble
   Sort��ð������ ��Insertion Sort���������� ��Radix
   Sort����������) ��Count Sort (��������)
   --------------------------Cxk 2019.1.21 */
#include<iostream>
#include<cstdlib>
#include <iomanip>
#include"random.h"
using namespace std;
#define MaxSize 10
// ��ʾ����
void displayArray(int a[]);
// ��������
void swap(int a[], int i, int j);
//����ϲ�
void mergearray(int a[],int first,int mid,int last,int temp[]);
// ѡ������
void selectionSort(int a[]);
// ð������
void bubbleSort(int a[]);
// ��������
void quickSort(int a[], int left, int right);
// �鲢����
void mergeSort(int a[],int first,int last);
// ��������
void insertionSort(int a[]);
// ��������
void radixSort(int a[], int n);
int maxbit(int a[], int n);
// ��������
void countSort(int a[],int n);
int main()
{
	int a[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		a[i] = randomInteger(0, 100);
	displayArray(a);
	cout << endl;
	// selectionSort(a);
	// bubbleSort(a);
	//quickSort(a, 0, 999999);
	// insertionSort(a);
	//radixSort(a, MaxSize);
	//countSort(a,MaxSize);
	mergeSort(a,0,9);
	displayArray(a);
	return 0;
}

void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void displayArray(int a[])
{
	for (int j = 0; j < MaxSize; j++)
	{
		cout << "[" << a[j] << "] ";
	}
	cout << endl;
}

/* 
   ð�ݹ��̣�
   1.��0λ�ÿ�ʼ���Ƚ������������Ĵ�С������������С��ǰ�棬�򽻻�λ�á� 
   2.����һ�����������һ����Ϊ���������е����ֵ��
   3.�����һ�����ų��������Ƚ�ʣ�µ�����
   4.�ܹ��Ƚϴ���ΪN*N��ʱ�临�Ӷ�ΪO��n2���� */
void bubbleSort(int a[])
{
	if (a == NULL || MaxSize < 2)
	{
		return;
	}
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; j < MaxSize - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a, j, j + 1);
			}
		}
	}
}

/* 
   ѡ����̣�
   ����һ�飬�ҵ�������������С��������λ��0��������λ�á� 
   ��1λ�ÿ�ʼ�������������ҵ���С��������1λ�ý������Դ����ơ�
   ͬð�����򣬸��Ӷ�ΪO��n2���� */
void selectionSort(int a[])
{
	if (a == NULL || MaxSize < 2)
	{
		return;
	}
	for (int i = 0; i < MaxSize; i++)
	{
		int min = i;
		for (int j = i + 1; j < MaxSize; j++)
		{
			min = a[j] < a[min] ? j : min;
		}
		swap(a, i, min);
	}
}

/* 
   ����������һ�ֺ���ҪҲ�ܳ��õ�����Ҳ��һЩ����Ҫ��Ӧ�ã�����˵BFPRT�㷨�������������⡣
   �����������ÿ�ζ�ѡ�����ֵ��������Сֵ���ͻ������������ʹ���ӶȴﵽO��n2�����𡣵��ǿ���ͨ�����ѡ��partitionֵ������ѧ�����ϱ�����������ķ��������Կ���Ĭ���临�Ӷ�ΪO��N 
   * lg N���� һ��Ĭ�Ͽ��������Ƿ��ȶ��ġ����������ļ���ķ���������ʹ��ʵ���ȶ���0-1 stable
   sort���� һ�˿���������㷨�ǣ� 1��������������i��j������ʼ��ʱ��i=0��j=N-1��
   2���Ե�һ������Ԫ����Ϊ�ؼ����ݣ���ֵ��key����key=A[0]��
   3����j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��ֵA[j]����A[j]��ֵ����A[i]��
   4����i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��A[i]����A[i]��ֵ����A[j]��
   5���ظ���3��4����ֱ��i=j��
   (3,4���У�û�ҵ�����������ֵ����3��A[j]��С��key,4��A[i]������key��ʱ��ı�j��i��ֵ��ʹ��j=j-1��i=i+1��ֱ���ҵ�Ϊֹ���ҵ�����������ֵ�����н�����ʱ��i��jָ��λ�ò��䡣���⣬i==j��һ����һ��������i+��j-��ɵ�ʱ�򣬴�ʱ��ѭ���������� 
 */
void quickSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;				// ���
	int j = right;				// �ұ�
	int key = a[left];
	while (i < j)
	{
		while (i < j && key <= a[j])	/* 1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ�������������ǽ���2��û�з��������ģ�����i��j�Ĵ�Сû�з�ת 
										 */
		{
			j--;
		}
		a[i] = a[j];			/* �ҵ�һ������������Ͱ�������ǰ��ı����ߵ�i��ֵ�������һ��ѭ����key��a[left]����ô���Ǹ�key�� 
								 */
		while (i < j && key > a[i])	/* ����i�ڵ�������ǰѰ�ң�ͬ�ϣ�����ע����key�Ĵ�С��ϵֹͣѭ���������෴,��Ϊ����˼���ǰ����������ӣ������������ߵ�����С��key�Ĺ�ϵ�෴ 
									 */
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	/* ���ڵ���������һ���Ժ�Ͱ��м���key�ع� */
	quickSort(a, left, i - 1);	/* �����ͬ���ķ�ʽ�Էֳ�������ߵ�С�����ͬ�ϵ����� 
								 */
	quickSort(a, i + 1, right);	/* ��ͬ���ķ�ʽ�Էֳ������ұߵ�С�����ͬ�ϵ�����,��Ȼ�����ܻ���ֺܶ�����ң�ֱ��ÿһ���i 
								   = j */
}
//����������a[]��b[]�ϲ���c[]
/*void MemeryArray(int a[], int n, int b[], int m, int c[])  
{  
    int i, j, k;  
  
    i = j = k = 0;  
    while (i < n && j < m)  
    {  
        if (a[i] < b[j])  
            c[k++] = a[i++];  
        else  
            c[k++] = b[j++];   
    }  
  
    while (i < n)  
        c[k++] = a[i++];  
  
    while (j < m)  
        c[k++] = b[j++];  
}*/
void mergearray(int a[],int first,int mid,int last,int temp[])	//��������������ϲ����� 
{
//	int temp[MaxSize];
	int i=first,j=mid+1;
	int m=mid,n=last;
	int k=0;
	while(i<=m&&j<=n)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=n)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[first+i]=temp[i];
}
 
void mergeSort(int a[],int first,int last)	
//��������������ϲ����� 
{
		int temp[MaxSize];
	if(first<last)
	{
		int mid=(first+last)/2;
		mergeSort(a,first,mid);	//������� 
		mergeSort(a,mid+1,last);	//�ұ����� 
		mergearray(a,first,mid,last,temp);	//�ٽ�������������ϲ� 
	}
}
/* 
   ����������̣�
   ��1λ�ÿ�ʼ���Ƚ���ǰ�����Ĵ�С�����С��ǰ��������򽻻�λ�ã�ֱ������С��ֹͣ�����Ŵ�2λ�ÿ�ʼ���ظ�������̡�ֱ�����λ��Ϊֹ��
   ʱ�临�Ӷ�ȡ�������������������������������ʱ�򣬸��ӶȺܵͣ��ӽ�O��n������������ȫ����ʱ��ÿ������Ҫ��������ƶ������Ӷ�������O��n2���� 
 */
void insertionSort(int a[])
{

	if (a == NULL || MaxSize < 2)
	{
		return;
	}
	for (int i = 0; i < MaxSize; i++)
	{
		// cout<<"����i��ֵ"<<i<<endl;
		for (int j = i - 1; j >= 0; j--)
		{
			// cout<<"����j��ֵ"<<j<<endl;
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

int maxbit(int a[], int n)	
	// ���������������ݵ����λ��
{
	int d = 1;					
	// ��������λ��
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (a[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
/*
����������̣�
�����д��Ƚ���ֵ����������ͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油�㡣Ȼ�󣬴����λ��ʼ�����ν���һ���������������λ����һֱ�����λ��������Ժ�, ���оͱ��һ���������С�
*/
void radixSort(int a[], int n)	
{
	int d = maxbit(a, n);
	int *tmp = new int[n];
	int *count = new int[10];
		// ������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)	
	// ����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;	
			// ÿ�η���ǰ��ռ�����
		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10;
				// ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];
			// ��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--)
			// ������Ͱ�м�¼�����ռ���tmp��
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < n; j++)
			// ����ʱ��������ݸ��Ƶ�data��
			a[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}
/*
��������Ĳ������£�

ͳ������A��ÿ��ֵA[i]���ֵĴ���������C[A[i]]

��ǰ���ʹ����C�е�ÿ��ֵ��������ǰһ����ӣ���������C[A[i]]�ͱ���˴�������A��С�ڵ���A[i]��Ԫ�ظ���

�������Ŀ������B��������Ԫ��A[i]��������B�ĵ�C[A[i]]��λ�ã��±�ΪC[A[i]] �C 1����ÿ��һ��Ԫ�ؾͽ�C[A[i]]�ݼ�
*/

void countSort(int a[], int n) {
	//�ҵ�����Ԫ��,���֪����Χ�Ͳ�����һ���ˣ�ֱ�ӿ�c����ͺ���
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
		max = a[i];
		//�����Ԫ�ش�������
	int* c = new int[max + 1];
	/*memcpy��memory copy����д����Ϊ�ڴ渴�ƣ���дC���Գ����ʱ�����ǳ������õ��������ĺ�ԭ�����£�
void *memcpy(void *dest, const void *src, size_t n);
���Ĺ����Ǵ�src�Ŀ�ʼλ�ÿ���n���ֽڵ����ݵ�dest�����dest�������ݣ����ᱻ���ǡ�memcpy�����ķ���ֵ��dest��ָ�롣memcpy����������string.hͷ�ļ��*/
	memset(c, 0, sizeof(int)*(max+ 1));
	//ͳ��ÿ��Ԫ���м���
	for (int j = 0; j < n;j++)
	++c[a[j]];	//��c��ǰ׺�ͣ�����ÿ��i��С�ڵ���i��Ԫ����c[i]��
	for (int k = 1; k <= max; k++)
	c[k] += c[k - 1];
	int* b = new int[n];
	//�������
	for (int l = n - 1; l >= 0; l--) {
		b[c[a[l]] - 1] = a[l];
		--c[l];
 
		//�ڶ��� //��ÿ��Ԫ��A[i]�ŵ������������B�е���ȷλ����,���������ظ�Ԫ��ʱ�ᱻ���ڵ�ǰԪ�ص�ǰһ��λ���ϱ�֤����������ȶ���
	//	b[--c[a[i]]] = a[i];
	}
	//���ƻ�ȥ
	//memcpy(a, b, sizeof(int)*n);
	for (int m = 0; m < n; m++)
	a[m] = b[m];
	delete[] b;
	delete[] c;
}