
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<future>
#include<thread>

using namespace std;

int tmp_main38() {

	packaged_task<int()> task([](){ return 7; });
	future<int> f1 = task.get_future();
	thread(move(task)).detach();

	future<int> f2 = async(launch::async, []() { return 8; });

	promise<int> p;
	future<int> f3 = p.get_future();
	thread( [&p]{ p.set_value_at_thread_exit(9); }).detach();

	cout << "Waiting..." << flush;
	f1.wait();
	f2.wait();
	f3.wait();
	cout << "Done! Results are: "
			<< f1.get() << " " << f2.get() << " " << f3.get() << endl;

	promise<void> ready_promise, t1_ready_promise, t2_ready_promise;
	shared_future<void> ready_future(ready_promise.get_future());

	chrono::time_point<chrono::high_resolution_clock> start;

	auto fun1 = [&, ready_future]() -> chrono::duration<double, milli>
	{
		t1_ready_promise.set_value();
		ready_future.wait();
		return chrono::high_resolution_clock::now() - start;
	};

	auto fun2 = [&, ready_future]() -> chrono::duration<double, milli>
	{
		t2_ready_promise.set_value();
		ready_future.wait();
		return chrono::high_resolution_clock::now() - start;
	};

	auto result1 = async(launch::async, fun1);
	auto result2 = async(launch::async, fun2);

	t1_ready_promise.get_future().wait();
	t2_ready_promise.get_future().wait();

	start = chrono::high_resolution_clock::now();

	ready_promise.set_value();

	cout << "Thread 1 received the signal "
			<< result1.get().count() << " ms after start " << endl
			<< "Thread 2 received the signal "
			<< result2.get().count() << "ms after start " << endl;

    return 0;
}
