// Helloworld.cpp : 定义控制台应用程序的入口点。
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

//这个函数测试静态初始化和函数内初始化区别
void f(int a)
{
	while (a--)
	{
		static int n = 0;
		int x = 0;
		cout << "n==" << n++ << " ,x==" << x++ << "\n";
	}
}

//这个函数测试形参和实参区别
void fuc(int m, int& n)
{
	m++;
	n++;
}
int main()
{
	//todo:输出一些文本
	cout << "hello world" << endl << endl;
	//todo:数据结构
	char * luoyi;
	int m = 9;
	int * p = &m;
	//Callback(5, Negate()); //输出 -5
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
	//todo:静态初始化和非静态初始化
	f(3);
	system("pause");
	int a1 = 3;
	int b1 = 3;
	//todo:形参 实参
	fuc(a1, b1);
	cout << "a==" << a1 << " ,b==" << b1 << "\n";
	system("pause");
	return 1;
	//return 0;
}




