#include "HPlane.h"

HPlane::HPlane(const HPlane& p): n(p.n), d(p.d) {}

HPlane::HPlane(const HVector& normal, float d): n(normal), d(d) {}

