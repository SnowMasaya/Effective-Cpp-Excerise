
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int tmp_main10(){

	enum class Color {black, white, red};

	std::vector<std::size_t> primeFactors(std::size_t x);

	Color c = Color::red;

	if (static_cast<double>(c) < 14.5){
	//	auto factor = primeFactors(static_cast<std::size_t>(c));
	}

	return 0;
}

