
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */
#include<iostream>
using namespace std;

class Fraction
{
	int gcd(int a, int b)
	{
		if(b == 0){
			return a;
		}else{
			return gcd(b, a % b);
		}
	}
	int n, d;
public:
	Fraction(int n, int d = 1): n(n/gcd(n, d)), d(d/gcd(n, d)) {}
	int num() const { return n; }
	int den() const { return d; }
	Fraction& operator*=(const Fraction& rhs)
	{
		int new_n = n * rhs.n/gcd(n * rhs.n, d * rhs.d);
		d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
		n = new_n;
		return *this;
	}
};

ostream& operator<<(ostream& out, const Fraction& f)
{
	return out << f.num() << '/' << f.den();
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	return !(lhs == rhs);
}
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
	return lhs *= rhs;
}

int main()
{
	Fraction f1(3, 8), f2(1, 2), f3(10,2);
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl
	     << f2 << " * " << f3 << " = " << f2 * f3 << endl
	     << 2 << " * " << f1 << " = " << 2 * f1 << endl;
	return 0;
}
