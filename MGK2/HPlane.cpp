#include "HPlane.h"

HPlane::HPlane(const HPlane& plane): n(plane.n), p(plane.p), d(plane.d) {}

HPlane::HPlane(float a, float b, float c, float d)
{
	this->n = {a, b, c};
    //this->n.Normalize();

    if (c != 0) {
        this->p = {0, 0, -d / c};
    } else if (b != 0) {
        this->p = {0, -d / b, c};
    }
}


