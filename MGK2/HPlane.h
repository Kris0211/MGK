#pragma once
#include "HVector.h"
class HPlane
{
	// NOPE, MA BY� POSTA� Z WEKTOREM NORMALNYM
public:
	HVector n;
	HVector p;

	float a, b, c, d;
	HPlane() {};
	HPlane(const HPlane& plane);
	HPlane(float a, float b, float c, float d);
};
