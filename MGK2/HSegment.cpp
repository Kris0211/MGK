#include "HSegment.h"

HSegment::HSegment(const HSegment& seg): s(seg.s), e(seg.s), v(seg.v) {}

HSegment::HSegment(const HVector& s, const HVector& e): s(s), e(e)
{
	this->v = e - s;
	this->v.Normalize();
}
