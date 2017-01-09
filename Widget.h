/*
 * Widge.h
 *
 *  Created on: Jan 9, 2017
 *      Author: masayaogushi
 */

#ifndef WIDGE_H_
#define WIDGE_H_

class Widget {
public:
	bool operator<(const Widget& other) const
	{
		return true;
	}
};

#endif /* WIDGE_H_ */
