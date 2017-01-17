
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<memory>
#include<utility>
#include<array>

using namespace std;

struct A {
	A(int&& n) { cout << "rvalue overload, n =" << n << endl; }
	A(int& n) { cout << "lvalue overload, n =" << n << endl; }
};

class B {
public:
	template<class T1, class T2, class T3>
	B(T1&& t1, T2&& t2, T3&& t3) :
	    a1_{forward<T1>(t1)},
	    a2_{forward<T2>(t2)},
	    a3_{forward<T3>(t3)}
	    {}
private:
	    A a1_, a2_, a3_;
};

template<class T, class U>
unique_ptr<T> make_unique1(U&& u)
{
	return unique_ptr<T>(new T(forward<U>(u)));
}

template<class T, class... U>
unique_ptr<T> make_unique(U&&... u)
{
	return unique_ptr<T>(new T(forward<U>(u)...));
}

int main() {

	auto p1 = make_unique1<A>(2);
	int i = 1;
	auto p2 = make_unique1<A>(i);

	cout << "B" << endl;
	auto t = make_unique<B>(2, i, 3);
}
