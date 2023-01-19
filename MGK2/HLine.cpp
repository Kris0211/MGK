#include "HLine.h"

#include <sstream>

HLine::HLine(const HLine& l): p(l.p), v(l.v) {}

HLine::HLine(const HVector& p, const HVector& v): p(p), v(v) {}

HLine HLine::StartToEnd(const HVector& s, const HVector& e)
{
	HLine ret;
	ret.p = s;
	ret.v = e - s;
	return ret;
}

std::string HLine::ToString()
{
	std::stringstream ss;
	ss << "P = " << p.ToString() << " + " << v.ToString() << " * t";
	return ss.str();
}
