
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<future>
#include<chrono>
#include<thread>

using namespace std;

void print_ten (char c, int ms) {
	for(int i = 0; i < 10; i++){
		this_thread::sleep_for (chrono::milliseconds(ms));
		cout << c;
	}
}

int tmp_main35() {
	cout << "with launch::async:" << endl;
	//future<void> foo = async (launch::async, print_ten, "*", 100);
	//future<void> bar = async (launch::async, print_ten, "@", 200);
	//foo.get();
	//bar.get();
	cout << endl;

	cout << "with launch::defferred:" << endl;
    //foo = async (launch::deferred, print_ten, "*", 100);
    //bar = async (launch::deferred, print_ten, "@", 200);
    //foo.get();
    //bar.get();
    cout << endl;

    return 0;
}
