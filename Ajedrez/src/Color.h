#pragma once
#include "freeglut.h"
typedef unsigned char uchar;

class Color
{
	uchar r{ 255 }, g{ 255 }, b{ 255 }; //color blanco
	void pon_color() {
		glColor3ub(r, g, b);
	}
};

