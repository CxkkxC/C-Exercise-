/* 
   排序算法总结 ①Selection Sort （选择排序) ②Merge
   Sort（归并排序） ③Quick Sort（快速排序） ④Bubble
   Sort（冒泡排序） ⑤Insertion Sort（插入排序） ⑥Radix
   Sort（基数排序) ⑦Count Sort (计数排序)
   --------------------------Cxk 2019.1.21 */
#include<iostream>
#include<cstdlib>
#include <iomanip>
#include"random.h"
using namespace std;
#define MaxSize 10
// 显示数组
void displayArray(int a[]);
// 交换数组
void swap(int a[], int i, int j);
//数组合并
void mergearray(int a[],int first,int mid,int last,int temp[]);
// 选择排序
void selectionSort(int a[]);
// 冒泡排序
void bubbleSort(int a[]);
// 快速排序
void quickSort(int a[], int left, int right);
// 归并排序
void mergeSort(int a[],int first,int last);
// 插入排序
void insertionSort(int a[]);
// 基数排序
void radixSort(int a[], int n);
int maxbit(int a[], int n);
// 计数排序
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
   冒泡过程：
   1.从0位置开始，比较相邻两个数的大小，如果后面的数小于前面，则交换位置。 
   2.遍历一遍下来，最后一个数为整个数组中的最大值。
   3.把最后一个数排除，继续比较剩下的数组
   4.总共比较次数为N*N，时间复杂度为O（n2）。 */
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
   选择过程：
   遍历一遍，找到整个数组中最小的数，与位置0的数交换位置。 
   从1位置开始，继续遍历，找到最小的数，与1位置交换。以此类推。
   同冒泡排序，复杂度为O（n2）。 */
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
   快速排序是一种很重要也很常用的排序，也有一些很重要的应用，比如说BFPRT算法，荷兰国旗问题。
   快速排序如果每次都选到最大值，或者最小值，就会产生最坏的情况，使复杂度达到O（n2）级别。但是可以通过随机选择partition值，从数学期望上避免这种情况的发生。所以可以默认其复杂度为O（N 
   * lg N）。 一般默认快速排序是非稳定的。但是有论文级别的方法，可以使其实现稳定（0-1 stable
   sort）。 一趟快速排序的算法是： 1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
   2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
   3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]的值赋给A[i]；
   4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]的值赋给A[j]；
   5）重复第3、4步，直到i=j；
   (3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i，j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。 
 */
void quickSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;				// 左边
	int j = right;				// 右边
	int key = a[left];
	while (i < j)
	{
		while (i < j && key <= a[j])	/* 1，找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）2，没有符合条件的，并且i与j的大小没有反转 
										 */
		{
			j--;
		}
		a[i] = a[j];			/* 找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是a[left]，那么就是给key） 
								 */
		while (i < j && key > a[i])	/* 这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反,因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反 
									 */
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;
	/* 当在当组内找完一遍以后就把中间数key回归 */
	quickSort(a, left, i - 1);	/* 最后用同样的方式对分出来的左边的小组进行同上的做法 
								 */
	quickSort(a, i + 1, right);	/* 用同样的方式对分出来的右边的小组进行同上的做法,当然最后可能会出现很多分左右，直到每一组的i 
								   = j */
}
//将有序数组a[]和b[]合并到c[]
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
void mergearray(int a[],int first,int mid,int last,int temp[])	//将两个有序数组合并排序 
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
//将两个任意数组合并排序 
{
		int temp[MaxSize];
	if(first<last)
	{
		int mid=(first+last)/2;
		mergeSort(a,first,mid);	//左边有序 
		mergeSort(a,mid+1,last);	//右边有序 
		mergearray(a,first,mid,last,temp);	//再将两个有序数组合并 
	}
}
/* 
   插入排序过程：
   从1位置开始，比较与前面数的大小，如果小于前面的数，则交换位置，直到不再小于停止。接着从2位置开始，重复这个过程。直到最后位置为止。
   时间复杂度取决于数组的排序情况，当数组基本有序时候，复杂度很低，接近O（n）。当数组完全无序时，每个数都要经过多次移动，复杂度趋近于O（n2）。 
 */
void insertionSort(int a[])
{

	if (a == NULL || MaxSize < 2)
	{
		return;
	}
	for (int i = 0; i < MaxSize; i++)
	{
		// cout<<"这是i的值"<<i<<endl;
		for (int j = i - 1; j >= 0; j--)
		{
			// cout<<"这是j的值"<<j<<endl;
			if (a[j] > a[j + 1])
				swap(a, j, j + 1);
		}
	}
}

int maxbit(int a[], int n)	
	// 辅助函数，求数据的最大位数
{
	int d = 1;					
	// 保存最大的位数
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
基数排序过程：
将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。
*/
void radixSort(int a[], int n)	
{
	int d = maxbit(a, n);
	int *tmp = new int[n];
	int *count = new int[10];
		// 计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)	
	// 进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;	
			// 每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10;
				// 统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];
			// 将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--)
			// 将所有桶中记录依次收集到tmp中
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < n; j++)
			// 将临时数组的内容复制到data中
			a[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
}
/*
计数排序的步骤如下：

统计数组A中每个值A[i]出现的次数，存入C[A[i]]

从前向后，使数组C中的每个值等于其与前一项相加，这样数组C[A[i]]就变成了代表数组A中小于等于A[i]的元素个数

反向填充目标数组B：将数组元素A[i]放在数组B的第C[A[i]]个位置（下标为C[A[i]] – 1），每放一个元素就将C[A[i]]递减
*/

void countSort(int a[], int n) {
	//找到最大的元素,如果知道范围就不用这一步了，直接开c数组就好了
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
		max = a[i];
		//以最大元素创建数组
	int* c = new int[max + 1];
	/*memcpy是memory copy的缩写，意为内存复制，在写C语言程序的时候，我们常常会用到它。它的函原型如下：
void *memcpy(void *dest, const void *src, size_t n);
它的功能是从src的开始位置拷贝n个字节的数据到dest。如果dest存在数据，将会被覆盖。memcpy函数的返回值是dest的指针。memcpy函数定义在string.h头文件里。*/
	memset(c, 0, sizeof(int)*(max+ 1));
	//统计每个元素有几个
	for (int j = 0; j < n;j++)
	++c[a[j]];	//对c求前缀和，对于每个i，小于等于i的元素有c[i]个
	for (int k = 1; k <= max; k++)
	c[k] += c[k - 1];
	int* b = new int[n];
	//反向填充
	for (int l = n - 1; l >= 0; l--) {
		b[c[a[l]] - 1] = a[l];
		--c[l];
 
		//第二种 //把每个元素A[i]放到它在输出数组B中的正确位置上,当再遇到重复元素时会被放在当前元素的前一个位置上保证计数排序的稳定性
	//	b[--c[a[i]]] = a[i];
	}
	//复制回去
	//memcpy(a, b, sizeof(int)*n);
	for (int m = 0; m < n; m++)
	a[m] = b[m];
	delete[] b;
	delete[] c;
}