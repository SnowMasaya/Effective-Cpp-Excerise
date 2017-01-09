
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Widget.h"
using namespace std;


int tmp_main9(){

    int f1(shared_ptr<Widget> spw);
    double f2(unique_ptr<Widget> upw);
    bool f3(Widget* pw);

	//std::mutex f1m, f2m, f3m;

	//using MuxGuard = std::lock_guard<std::mutex>;

	//{
	//	MuxGuard g(f3m);
	//	auto result = f3(nullptr);
	//}

	return 0;
}

