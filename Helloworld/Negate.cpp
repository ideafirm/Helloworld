#include "stdafx.h"
#include "Negate.h"
#include <iostream>
using std::cout;

Negate::Negate()
{
}


Negate::~Negate()
{
}

int test1() {
	//int * p;
	char * luoyi;
	int m = 9;
	int * p = &m;
	return 1;
};

void Callback(int n, Negate & neg)
{
	int val = neg(n); //�������صĲ�������()��
	cout << val;
}