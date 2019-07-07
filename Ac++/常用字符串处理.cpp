#include<iostream>
#include<string>
#include"strlib.h"
//常用字符串处理库
#include<cctype>
/* 字符串常用库 包含toupper(ch),tolower(ch)…… */
#include<sstream>
using namespace std;
string repeatChar(int n, char ch);
string reverse(string str);
bool isPalindrome(string str);
bool isPalindrome2(string str);
string integerToString(int n) {  
   ostringstream stream;  
   stream << n;  
   return stream.str();  
}  
int main()
{
	string str3=integerToString(300);
	cout<<str3;
	string str1 = "Hello, world";
	str1.at(0) = 'h';
	// 需要检测并确保索引在字符串合法的取值范围内
	str1[0] = 'c';
	// 不需要
	string str2 = "Cxk";
	// str1=str2;
	// cout << str1.substr(1, 3);
	/* 提取字符串中的子串从下标1开始为"ell" */
	// cout<<str1<<endl;
	// cout<<str1.find('e');
	/* 搜索字符串 */
	for (int i = 0; i < str1.length(); i++)
	{
		cout << str1[i] << "  ";

	}
	// 遍历字符串
/*	cout << repeatChar(1000, '2') << endl;
	cout << reverse("desserts") << endl;
	cout << isPalindrome2("acdca") << endl;
*/	return 0;
}

/* 通过链接扩展字符串 */
string repeatChar(int n, char ch)
{
	string str = "";
	for (int i = 0; i < n; i++)
		str += ch;
	return str;
}

/* 将连接和迭代模式连起来用，倒序输出参数字符串 */
string reverse(string str)
{
	string rev = "";
	for (int i = str.length() - 1; i >= 0; i--)
		rev += str[i];
	// rev += toupper(str[i]);
	// /*返回参数对应的大写字母，tolower(ch)->返回对应参数的小写字母。头文件#include<cctype>*/
	return rev;
}

// 判断是否回文
bool isPalindrome(string str)
{
	return str == reverse(str);
	// 调用倒序输出函数，回文则是正读与反读一致
}

bool isPalindrome2(string str)
{
	int n = str.length();
	// 中间截断，前跟后判断是否相等
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - i - 1])
			return false;
	}
	return true;
}
