// Helloworld.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Negate.h"

using namespace std;
struct person {
	char name;
	int age;
	bool sex;
};

//����������Ծ�̬��ʼ���ͺ����ڳ�ʼ������
void f(int a)
{
	while (a--)
	{
		static int n = 0;
		int x = 0;
		cout << "n==" << n++ << " ,x==" << x++ << "\n";
	}
}

//������������βκ�ʵ������
void fuc(int m, int& n)
{
	m++;
	n++;
}
int main()
{
	//todo:���һЩ�ı�
	cout << "hello world" << endl << endl;
	//todo:���ݽṹ
	char * luoyi;
	int m = 9;
	int * p = &m;
	//Callback(5, Negate()); //��� -5
	int a[10];
	float v[3];
	char luoyichar[5];
	//char * luoyi[5];
	luoyichar[0] = 'a';
	luoyichar[1] = 'b';
	luoyichar[2] = 'c';
	luoyichar[3] = 'd';
	luoyichar[4] = 'e';
	//luoyichar[5] = { 'l' };
	const float PI = 3.14159;
	cout << PI << endl << endl;
	system("pause");
	//todo:��̬��ʼ���ͷǾ�̬��ʼ��
	f(3);
	system("pause");
	int a1 = 3;
	int b1 = 3;
	//todo:�β� ʵ��
	fuc(a1, b1);
	cout << "a==" << a1 << " ,b==" << b1 << "\n";
	system("pause");
	return 1;
	//return 0;
}




