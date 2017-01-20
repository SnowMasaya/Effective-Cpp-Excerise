
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<atomic>
#include<thread>
#include<vector>

using namespace std;

atomic<bool> ready (false);
atomic_flag winter = ATOMIC_FLAG_INIT;

void countlm(int id) {
	while (!ready) { this_thread::yield();}
	for (volatile int i = 0; i < 1000000; ++i) {}
	if (!winter.test_and_set ()) { cout << "thread #" << id << "won!" << endl;}
};

int tmp_main40() {
	vector<thread> threads;
	cout << "spawing 10 threads that count to 1 million..." << endl;
	for(int i =1; i <= 10; ++i) threads.push_back(thread(countlm, i));
	ready = true;
	for(auto& th : threads) th.join();
    return 0;
}
