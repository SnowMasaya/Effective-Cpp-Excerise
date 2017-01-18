
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<random>
#include<memory>
#include<functional>

using namespace std;
using namespace std::placeholders;

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
}

int g(int n1)
{
	return n1 + 1;
}

struct Foo {
	void print_sum(int n1, int n2)
	{
		cout << n1 + n2 << endl;
	}
	int data = 10;
};

int main() {
	int n = 7;
	auto f1 = bind(f, _2, _1, 42, cref(n), n);
	n = 10;
	f1(1, 2, 1001);

	auto f2 = bind(f, _3, bind(g, _3), _3, 4, 5);
	f2(10, 11, 12);

	default_random_engine e;
	uniform_int_distribution<> d(0, 10);
	function<int()> rnd = bind(d, e);
	for(int n = 0; n < 10; ++n){
		cout << rnd() << " ";
	}
	cout << endl;

	Foo *foo;
	//auto f3 = bind(&Foo::print_sum, &foo, 95, _1);
	auto f3 = bind(&Foo::print_sum, foo, 95, _1);
	f3(5);
}
