
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */
#include<iostream>
#include<memory>
using namespace std;

struct Foo
{
	Foo() {cout << "Foo:Foo" << endl;}
	~Foo() {cout << "Foo:~Foo" << endl;}
	void bar() {cout << "Foo:bar" << endl;}
};

void f(const Foo &)
{
	cout << "f(const Foo&)" << endl;
}

int tmp_main18()
{
	unique_ptr<Foo> p1(new Foo);

	if(p1) p1->bar();

	{
		unique_ptr<Foo> p2(move(p1));
		f(*p2);

		p1 = move(p2);
		cout << "destorying p2..." << endl;
	}

	if(p1) p1->bar();

	return 0;
}
