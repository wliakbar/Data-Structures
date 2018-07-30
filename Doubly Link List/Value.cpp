/*
 * Value.cpp
 *
 *  Created on: Jul 7, 2018
 *      Author: wliakbar
 */
#include "Key.h"
#include "Value.h"


Value::Value(int x, Key* y, Key* z) {
	values=x;
	headptr=y;
	prevptr=z;

}
