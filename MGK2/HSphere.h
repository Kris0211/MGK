#pragma once
#include "HVector.h"

class HSphere
{
	HVector p;
	float r;

	HSphere();
	HSphere(const HSphere& s);
	HSphere(HVector p, float r);
};
