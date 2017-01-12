
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<memory>

using namespace std;

struct Vec3
{
	int x, y, z;
	Vec3() : x(0), y(0), z(0) { }
	Vec3(int x, int y, int z) : x(x), y(y), z(z) {}
	friend ostream& operator<<(ostream& os, Vec3& v) {
		return os << "{" << "x:" << v.x << " y:" << v.y << " z:" << v.z << "}";
	}
};

void foo(const shared_ptr<int>& i)
{
	(*i)++;
}

int tmp_main21()
{
	auto sp = make_shared<int>(12);
	foo(sp);
	cout << *sp << endl;

	//unique_ptr<Vec3> v1 = std::make_unique<Vec3>();
	//unique_ptr<Vec3> v2 = make_unique<Vec3>(0, 1, 2);
	//unique_ptr<Vec3[]> v3 = make_unique<Vec3>(5);

	//cout << "make_unique<Vec3>(): "        << *v1 << endl
	//     << "make_unique<Vec3>(0, 1, 2): " << *v2 << endl
	//     << "make_unique<Vec3[]>(5): "  << endl;
	//for(int i = 0; i < 5; i++){
	//	cout << " " << v3[i] << endl;
	//}
}
