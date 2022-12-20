#pragma once
#include "HVector.h"

class HSphere
{
public:
	HVector c;
	float r;

	HSphere();
	HSphere(const HSphere& s);
	HSphere(HVector p, float r);
};
