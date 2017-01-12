
/*
 * case1_const.cpp
 *
 *  Created on: Jan 8, 2017
 *      Author: masayaogushi
 */

#include<iostream>
#include<memory>
#include <experimental/propagate_const>

using namespace std;

class widget{
	class impl;
	std::experimental::propagate_const<unique_ptr<impl>> pImpl;
public:
	void draw() const;
	void draw();
	bool shown() const { return true; }
	widget(int);
	~widget();
	widget(widget&&) = default;
	widget(const widget&) = delete;
	widget& operator=(widget&&);
	widget& operator=(const widget&&) = delete;
};

class widget::impl {
	int n;
public:
	void draw(const widget& w) const {
		if(w.shown())
			cout << " drawing a const widget " << endl;
	}
	void draw(const widget& w) {
		if(w.shown())
			cout << " drawing a non-const widget " << endl;
	}
	impl(int n) : n(n) {}
};
void widget::draw() const  {pImpl->draw(*this);}
void widget::draw() {pImpl->draw(*this);}
widget::widget(int n) : pImpl{make_unique<impl>(n)} {}
widget::~widget() = default;
widget& widget::operator=(widget&&) = default;

int main()
{
	widget w(7);
	const widget w2(8);
	w.draw();
	w2.draw();
}
