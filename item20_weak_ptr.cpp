
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<memory>

using namespace std;

weak_ptr<int> gw;

void f()
{
	cout << "use count == " << gw.use_count() << ": ";
	if(auto spt = gw.lock()){
		cout << *spt << endl;
	}
	else {
		cout << "gw is expired" << endl;
	}
}

int tmp_main20()
{
	{
		auto sp = make_shared<int>(42);
		gw = sp;

		f();
	}

	f();
}
