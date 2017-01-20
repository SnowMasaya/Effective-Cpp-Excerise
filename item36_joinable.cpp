
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void foo2()
{
	this_thread::sleep_for(chrono::seconds(1));
}

int tmp_main36() {
	thread t;
	cout << "before starting joinable: " << t.joinable() << endl;

	t = thread(foo2);
	cout << "after starting joinable: " << t.joinable() << endl;

	t.join();
	cout << "after joining, joinable: " << t.joinable() << endl;

    return 0;
}
