#pragma once
#include "HVector.h"
class HPlane
{
	// NOPE, MA BY� POSTA� Z WEKTOREM NORMALNYM
public:
	HVector n;
	float d;
	HPlane() {};
	HPlane(const HPlane& p);
	HPlane(const HVector& normal, float d);
};
