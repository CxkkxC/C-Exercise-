/*在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。*/ 
#include<iostream>
using namespace std; 
  /*bool Find(int target, int array[][]) 
  {
}*/ 
int main(){
	int target;
	cin>>target;
	int c=0,d=0;
	int array[5][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}};
	int i,j;
        for(i = 4,j = 0;i >= 0 && j < 5;){
            if(target == array[i][j]){
              c=i;
              d=j;
            }
            else if(target > array[i][j]){
                j++;
                continue;
            }
            else if(target < array[i][j]){
                i--;
                continue;
            }
        }

/*	for(int i = 0;i < 5;i++){
		for(int j = 0;j<5;j++){
			if(n==a[i][j])
			{
				c=i;
				d=j;
			 } 
		}
		}*/
		cout<<"a["<<c<<"]["<<d<<"]"<<endl; 
	return 0;
}
