/* ʵ����ͼ̳У�����Ҫ�����£�
����һ��Person�࣬�������»�����Ϣ���������Ա����䡣
����Ҫ����Ϊ�ַ�����ָ������������Զ��塣
���幹�캯����ɸ�ֵ����������Ҫ��new�����ռ�
�����޲ι��캯������������Ϊ�ջ�0
����������������ɶ�̬�ռ���ա�
���������ֵ�ĺ�������ȡ���䡣
���������ֵ�ĺ�������ȡ�Ա�
������ʾ����show�����ֵ����ʾ��Ҫ������������ʾ��Ϣ��
����Student�࣬���м̳�Person�࣬
Ҫ�����������������༶��ѧ�š��༶Ҫ����Ϊ�ַ�����ָ�����
���幹�캯����ɸ�ֵ�����а༶Ҫ��new������̬�ռ䡣
����������������ɶ�̬�ռ���ա�
������ʾ����show�����ֵ����ʾ��Ҫ������������ʾ��Ϣ���������������ݣ����������ݣ� 
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
		cout << "\n������" << name << "\n��ͣ�" << age << "\n�Ա�" <<sex;
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
		cout << "\n�꼶:" << grade << "\nѧ�ţ�" << IDnumber;
	}
};
int main() {
	Person a("����", 21, "Ů");
	a.show();
	cout << "\n\n�Ա�:" << a.getSex() << "\n" << "����:" << a.getAge() << endl;
	Student b("����", 21, "Ů", "17�����6��", "511721010666");
	b.show();
	cout << endl;
	return 0;
}