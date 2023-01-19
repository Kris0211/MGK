#pragma once
#include "HVector.h"

class HLine
{
public:
	HVector p;
	HVector v;

	HLine() {};
	HLine(const HLine& l);
	HLine(const HVector& p, const HVector& v);
	static HLine StartToEnd(const HVector& s, const HVector& e);
	std::string ToString();
};
