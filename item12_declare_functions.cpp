
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <vector>
using namespace std;

class Base{
public:
	virtual void mf1() const;
	virtual void mf2(int x);
	virtual void mf3() &;
	virtual void mf4() const;
};

class Derived: public Base {
public:
	virtual void mf1() const override;
	virtual void mf2(int x) override;
	virtual void mf3() & override;
	void mf4() const override;
};

class Widget {
public:
	using DataType = std::vector<double>;

	DataType& data() &
	{return values;}

private:
	DataType values;
};

int tmp_main12(){

	Widget makeWidget();

	Widget w;

	auto vals1 = w.data();

	//auto vals2 = makeWidget().data();

	return 0;
}

