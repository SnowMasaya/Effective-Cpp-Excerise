
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<locale>

using namespace std;

int f(int) { return 1; }
int f(double) { return 2; }

void g( int(&f1)(int), int(*f2)(double)){}

template< int(*F)(int) >
struct Templ {};

struct Foo {
	int mf(int) {return 3;}
	int mf(double) {return 4;}
};

int (*(foo)(void))(int) {
	return f;
}

int main()
{
	int (*pf)(double) = f;
	int (&rf)(int) = f;
	int (Foo::*mpf)(int) = &Foo::mf;

	pf = nullptr;
	pf = &f;

	g(f, f);

	string str = "example";
	transform(str.begin(), str.end(), str.begin(),
			static_cast<int(*)(int)>(std::toupper));
	cout << str << endl;
	Templ<f> t;
}
