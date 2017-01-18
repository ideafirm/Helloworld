// TestStaticFunc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdafx.h"  
#include <iostream>  
using namespace std;
//静态函数练习  
void f(int a)
{
	while (a--)
	{
		// n只初始化一次，循环执行一次n会发生变化  
		static int n = 0;
		//x是局部变量，每次函数调用都初始化为0；  
		int x = 0;
		cout << "n==" << n++ << " ,x==" << x++ << "\n";
		//如果a = 3 则输出结果应该为  
		//n==0,x==0  
		//n==1,x==0  
		//n==2,x==0  
	}
}

//引用参数例子  
void fuc(int m, int& n)
{
	//m是值参数，在函数内部操作的是个副本，不会更改调用的数值    
	m++;
	cout << "m在函数内部被改变了 m=" << m << "\n";
	//n是引用参数，操作的是地址，外部调用的地方也会发生变化  
	n++;
	cout << "n在函数里也被改变了 n=" << n << "\n";
}

//地址参数  
void swap(int *m, int *n)
{
	//m和n传入的都是地址  
	int p = *n;
	*n = *m;
	*m = p;
	//函数实现了参数数值交换  
}

//地址参数  
void swapA(int *m, int n)
{
	//m是传入的地址   
	int i = *m;
	*m = n;
	n = i;
	//外部来说，m会发生变化，n不会变化  
}


//int _tmain(int argc, _TCHAR* argv[])
//{
//	
//}
int main()
{
	int a = 6;
	int b = 3;
	cout << "静态函数练习：\n";
	f(3);
	cout << "值参数练习：\n";
	cout << "传入的数值分别是：a = " << a << " b=" << b << "\n";
	fuc(a, b);
	cout << "执行函数fuc(int m, int& n)之后：\n";
	cout << "a = " << a << "b= " << b << "\n";

	cout << "交换之前 a， b 的数值：\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	swap(&a, &b);
	cout << "经过函数swap(&a, &b)之后 \n";
	cout << "a==" << a << " ,b==" << b << "\n";

	cout << "交换之前 a， b 的数值：\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	swapA(&a, b);
	cout << "经过函数swapA(&a, b)之后 \n";
	cout << "a==" << a << " ,b==" << b << "\n";

	a = a + b;
	cout << "交换之前 a， b 的数值：\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	fuc(a, b);
	cout << "经过函数fuc(int m, int& n)之后 \n";
	cout << "a==" << a << " ,b==" << b << "\n";
	system("pause");
	return 0;
}

