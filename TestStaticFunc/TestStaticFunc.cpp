// TestStaticFunc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdafx.h"  
#include <iostream>  
using namespace std;
//��̬������ϰ  
void f(int a)
{
	while (a--)
	{
		// nֻ��ʼ��һ�Σ�ѭ��ִ��һ��n�ᷢ���仯  
		static int n = 0;
		//x�Ǿֲ�������ÿ�κ������ö���ʼ��Ϊ0��  
		int x = 0;
		cout << "n==" << n++ << " ,x==" << x++ << "\n";
		//���a = 3 ��������Ӧ��Ϊ  
		//n==0,x==0  
		//n==1,x==0  
		//n==2,x==0  
	}
}

//���ò�������  
void fuc(int m, int& n)
{
	//m��ֵ�������ں����ڲ��������Ǹ�������������ĵ��õ���ֵ    
	m++;
	cout << "m�ں����ڲ����ı��� m=" << m << "\n";
	//n�����ò������������ǵ�ַ���ⲿ���õĵط�Ҳ�ᷢ���仯  
	n++;
	cout << "n�ں�����Ҳ���ı��� n=" << n << "\n";
}

//��ַ����  
void swap(int *m, int *n)
{
	//m��n����Ķ��ǵ�ַ  
	int p = *n;
	*n = *m;
	*m = p;
	//����ʵ���˲�����ֵ����  
}

//��ַ����  
void swapA(int *m, int n)
{
	//m�Ǵ���ĵ�ַ   
	int i = *m;
	*m = n;
	n = i;
	//�ⲿ��˵��m�ᷢ���仯��n����仯  
}


//int _tmain(int argc, _TCHAR* argv[])
//{
//	
//}
int main()
{
	int a = 6;
	int b = 3;
	cout << "��̬������ϰ��\n";
	f(3);
	cout << "ֵ������ϰ��\n";
	cout << "�������ֵ�ֱ��ǣ�a = " << a << " b=" << b << "\n";
	fuc(a, b);
	cout << "ִ�к���fuc(int m, int& n)֮��\n";
	cout << "a = " << a << "b= " << b << "\n";

	cout << "����֮ǰ a�� b ����ֵ��\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	swap(&a, &b);
	cout << "��������swap(&a, &b)֮�� \n";
	cout << "a==" << a << " ,b==" << b << "\n";

	cout << "����֮ǰ a�� b ����ֵ��\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	swapA(&a, b);
	cout << "��������swapA(&a, b)֮�� \n";
	cout << "a==" << a << " ,b==" << b << "\n";

	a = a + b;
	cout << "����֮ǰ a�� b ����ֵ��\n";
	cout << "a==" << a << " ,b==" << b << "\n";
	fuc(a, b);
	cout << "��������fuc(int m, int& n)֮�� \n";
	cout << "a==" << a << " ,b==" << b << "\n";
	system("pause");
	return 0;
}

