/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。
*/
/*
思路：我们从字符串的末尾开始复制和替换。

 1、定义两个指针，p1和p2。p1指向原始字符串的末尾，p2指向替换后字符串的末尾。

 2、向前移动指针p1，逐个把它指向的字符复制到p2指向的位置，
 直到碰到第一个空格为止。碰到第一个空格后，p1向前移动一格，
 然后在p2之前插入字符串“20%”。同时也要把p2向前移动3格。

 3、重复第2步，直到p1和p2指向同一位置，说明所有空格都已替换完。

*/
#include<iostream>
#include<string.h> 
using namespace std;
void replaceSpace(char *str,int length) {
    int oldlen=strlen(str);
    int sum=0;
    int newlen;
    for(int i=0;i<oldlen;i++){
        if(str[i]==' ')
            sum++;
    }
    newlen=oldlen+sum*2;
    int p1=oldlen;
    int p2=newlen;
    str[newlen]='\0';
    while(p1>0&&p2>0){
      if(str[p1]==' '){
          str[p2]='0';
          str[p2-1]='2';
          str[p2-2]='%';
          p1--;
          p2=p2-3;
      }
      else
          str[p2--]=str[p1--];
    }
    cout<<str<<endl;    
}
int main(){
	char str[100]="we are student1"; 
	replaceSpace(str,100);
	return 0;
}
