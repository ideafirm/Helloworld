#pragma once
class Negate
{
public:
	Negate();
	~Negate();

	int operator() (int n) {return -n;}
};