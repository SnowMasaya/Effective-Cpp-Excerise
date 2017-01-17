
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<type_traits>
#include<iostream>
#include<string>

using namespace std;

namespace detail { struct inplace_t{}; }
void* operator new(size_t, void* p, detail::inplace_t) {
	return p;
}

template<class T, class... Args>
typename enable_if<is_trivially_constructible<T, Args&&...>::value>::type
    construct(T* t, Args&&... args)
{
	cout << "constructing trivially constructible T" << endl;
}

template<class T, class...Args>
enable_if<!is_trivially_constructible<T, Args&&...>::value>
    construct(T* t, Args&&... args)
{
	cout << "constructing non-trivially constructible T" << endl;
	new(t, detail::inplace_t{}) T(args...);
}

template<class T>
void destroy(T* t,
		typename enable_if<is_trivially_destructible<T>::value>::type* = 0)
{
	cout << "destroying trivially destructible T" << endl;
}

