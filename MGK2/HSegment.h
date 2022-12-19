#pragma once
#include "HVector.h"

class HSegment
{
public:
	// start, end
	HVector s;
	HVector e;
	HVector v;

	HSegment() {}
	HSegment(const HSegment& seg);
	HSegment(const HVector& s, const HVector& e);
};
