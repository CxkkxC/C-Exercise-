/* 实现类和继承，具体要求如下：
定义一个Person类，包括如下基本信息：姓名，性别，年龄。
姓名要定义为字符类型指针变量，其他自定义。
定义构造函数完成赋值。其中姓名要用new创建空间
定义无参构造函数，变量设置为空或0
定义析构函数，完成动态空间回收。
定义带返回值的函数，获取年龄。
定义带返回值的函数，获取性别。
定义显示函数show，完成值的显示，要给出完整的提示信息。
定义Student类，公有继承Person类，
要求：增加两个变量，班级和学号。班级要定义为字符类型指针变量
定义构造函数完成赋值，其中班级要用new创建动态空间。
定义析构函数，完成动态空间回收。
定义显示函数show，完成值的显示，要给出完整的提示信息。（保留父类内容，增加新内容） 
*/
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
	char *name;
	int age;
	string sex;
public:
    Person(char *N, int a, string s) {
		int len = strlen(N);
		if (len <= 1)
			name = NULL;
		else {
			name = new char[len + 1];
			strcpy(name, N);
		} sex = s;
		age = a;
	}
	Person() {
	}
	~Person() {
		if (name != 0)
			delete[]name;
	}
	int getAge() {
		return this->age;
	}
	string getSex() {
		return sex;
	}
	void show() {
		cout << "\n姓名：" << name << "\n年纪：" << age << "\n性别：" <<sex;
	}
};
class Student:public Person {
private:
	char *grade;
	string IDnumber;
public:
    Student(char *N, int a, string s, char *G, string ID):Person(N, a, s) {
		int len2 = strlen(G);
		if (len2 <= 0)
			grade = NULL;
		else {
			grade = new char[len2 + 1];
			strcpy(grade, G);
		} IDnumber = ID;
	}
	~Student() {
		if (grade != 0)
			delete[]grade;
	}
	void show() {
		Person::show();
		cout << "\n年级:" << grade << "\n学号：" << IDnumber;
	}
};
int main() {
	Person a("王丽", 21, "女");
	a.show();
	cout << "\n\n性别:" << a.getSex() << "\n" << "年龄:" << a.getAge() << endl;
	Student b("王丽", 21, "女", "17计算机6班", "511721010666");
	b.show();
	cout << endl;
	return 0;
}