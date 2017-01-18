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
	int val = neg(n); //调用重载的操作符“()”
	cout << val;
}