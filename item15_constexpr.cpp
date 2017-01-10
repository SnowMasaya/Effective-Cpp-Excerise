
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */


#include<iostream>
#include<stdexcept>
using namespace std;

constexpr int factorial(int n)
{
	return n <= 1? 1 : (n * factorial(n - 1));
}

class conststr {
	const char* p;
	size_t sz;
public:
	template<size_t N>
	constexpr conststr(const char(&a)[N]): p(a), sz(N - 1) {}

	constexpr char operator[](size_t n) const
	{
		return n < sz? p[n] : throw out_of_range("");
	}
	constexpr size_t size() const {return sz;}
};

constexpr size_t countlower(conststr s, size_t n =0,
										size_t c = 0)
{
	return n == s.size()? c : 'a' <= s[n] && s[n] <= 'z' ? countlower(s, n + 1, c + 1) : countlower(s, n + 1, c);
}

template<int n>
struct constN
{
	constN() {cout << n << endl;}
};

int tmp_main15()
{

	cout << "4! = ";
	constN<factorial(4)> out1;

	volatile int k = 8;
	cout << k << "! = " << factorial(k) << endl;

	cout << "the number of lowlercase letters in Hello world is ";
	constN<countlower("Hello, world")> out2;

	return 0;
}
