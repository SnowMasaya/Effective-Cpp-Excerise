
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<utility>

using namespace std;

void f(int& x)
{
	cout << "lvalue reference overload f(" << x << ")" << endl;
}

void f(const int& x)
{
	cout << "lvalue referenceto const overload f(" << x << ")" << endl;
}

void f(int&& x)
{
	cout << "rvalue referenceto const overload f(" << x << ")" << endl;
}

int tmp_main24()
{
	int i = 1;
	const int ci = 2;

	f(i);
	f(ci);
	f(3);

	f(std::move(i));
}
