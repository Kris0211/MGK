#include "HLine.h"

#include <sstream>

HLine::HLine(const HLine& l): p(l.p), v(l.v) {}

HLine::HLine(const HVector& s, const HVector& e)
{
	this->p = s;
	this->v = e - s;
}

std::string HLine::ToString()
{
	std::stringstream ss;
	ss << "P = " << p.ToString() << " + " << v.ToString() << " * t";
	return ss.str();
}
