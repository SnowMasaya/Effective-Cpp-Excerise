
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<vector>

using namespace std;

struct A
{
	A(int) {}
	A(int, int) {}
	operator bool() const { return true; }
};

struct B
{
	explicit B(int) { }
	explicit B(int, int) { }
	explicit operator bool() const { return true; }
};

int main() {
	vector<int> myvector = {10, 20, 30};

	auto it = myvector.emplace( myvector.begin()+1, 100);
	myvector.emplace( it, 200);
	myvector.emplace( myvector.end(), 300);

	cout << "myvector contains:";
	for(auto& x: myvector){
		cout << " " << x;
	}
	cout << endl;

	A a1 = 1;
	A a2(2);
	A a3 {4, 5};
	A a4 = {4, 5};
	A a5 = (A)1;
	if(a1) ;
	bool na1 = a1;
	bool na2 = static_cast<bool>(a1);

	B b2(2);
	B b3 {4, 5};
	B b5 = (B)1;
	if(b2);

    return 0;
}
