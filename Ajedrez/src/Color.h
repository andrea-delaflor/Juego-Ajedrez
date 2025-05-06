#pragma once
#include "freeglut.h"
typedef unsigned char ucharb; //blanco
typedef unsigned char ucharn; //negro

class Color
{
	ucharb r{ 255 }, g{ 255 }, b{ 255 }; //color blanco
	ucharn r{ 0 }, g{ 0 }, b{ 0 }; //color negro
	void pon_color() {
		glColor3ub(r, g, b);
	}
};

