/*
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.
�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/
/*
˼·�����Ǵ��ַ�����ĩβ��ʼ���ƺ��滻��

 1����������ָ�룬p1��p2��p1ָ��ԭʼ�ַ�����ĩβ��p2ָ���滻���ַ�����ĩβ��

 2����ǰ�ƶ�ָ��p1���������ָ����ַ����Ƶ�p2ָ���λ�ã�
 ֱ��������һ���ո�Ϊֹ��������һ���ո��p1��ǰ�ƶ�һ��
 Ȼ����p2֮ǰ�����ַ�����20%����ͬʱҲҪ��p2��ǰ�ƶ�3��

 3���ظ���2����ֱ��p1��p2ָ��ͬһλ�ã�˵�����пո����滻�ꡣ

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
