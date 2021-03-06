
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<string>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
mutex m;
condition_variable cv;
string data;
bool ready1 = false;
bool processed = false;

void worker_thread()
{
	unique_lock<mutex> lk(m);
	cv.wait(lk, []{return ready1;});

	cout << "Worker thread is processing data " << endl;
	data += " after processing";

	processed = true;
	cout << "Worker thread signals data processing completed" << endl;

	lk.unlock();
	cv.notify_one();
}

int tmp_main39() {

	thread worker(worker_thread);

	data = "Example data";
	{
		lock_guard<mutex> lk(m);
		ready1 = true;
		cout << "main() signals data ready for processing " << endl;
	}
	cv.notify_one();

	{
		unique_lock<mutex> lk(m);
		cv.wait(lk, []{return processed;});
	}
	cout << "Back in main(), data = " << data << endl;

	worker.join();

    return 0;
}
