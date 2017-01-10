
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */


#include<iostream>
#include<utility>
#include<vector>
using namespace std;

void may_throw();
void no_throw() noexcept;
auto lmay_throw = []{};
auto lno_throw = []() noexcept {};
class T{
public:
	~T(){}
};
class U{
public:
	~U(){}

	std::vector<int>v;
};
class V{
public:
	std::vector<int>v;
};


int tmp_main14()
{
	T t;
	U u;
	V v;

	cout << boolalpha
			<< "Is may_throw noexcept? " << noexcept(may_throw()) << "\n"
			<< "Is no_throw noexcept? " << noexcept(no_throw()) << endl
			<< "Is lmay_throw noexcept? " << noexcept(lmay_throw()) << endl
			<< "Is lno_throw noexcept? " << noexcept(lno_throw()) << endl
			<< "Is T(rvalue T) noexcept? " << noexcept(T(declval<T>())) << endl
			<< "Is T(lvalue T) noexcept? " << noexcept(T(t)) << endl
			<< "Is U(rvalue U) noexcept? " << noexcept(U(declval<U>())) << endl
			<< "Is U(lvalue U) noexcept? " << noexcept(U(u)) << endl
			<< "Is V(lvalue V) noexcept? " << noexcept(V(declval<V>())) << endl
			<< "Is V(rvalue V) noexcept? " << noexcept(V(v)) << endl;

	return 0;
}
