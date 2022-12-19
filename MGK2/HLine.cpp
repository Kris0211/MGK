#include "HLine.h"

HLine::HLine(const HLine& l): p(l.p), v(l.v) {}

HLine::HLine(const HVector& s, const HVector& e)
{
	this->p = s;
	this->v = e - s;
	this->v.Normalize();
}
