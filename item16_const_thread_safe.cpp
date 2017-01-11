
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */
#include<mutex>
#include<thread>
#include<iostream>
using namespace std;

int g_i = 0;
mutex g_i_mutex;

void safe_increment()
{
	lock_guard<mutex> lock(g_i_mutex);
	++g_i;

	cout << this_thread::get_id() << ": " << g_i << endl;
}

int tmp_main16()
{
	cout << __func__ << ": " << g_i << endl;

	thread t1(safe_increment);
	thread t2(safe_increment);

	t1.join();
	t2.join();

	cout << __func__ << ": " << g_i << endl;
}
