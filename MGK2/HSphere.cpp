#include "HSphere.h"

HSphere::HSphere(const HSphere& s): p(s.p), r(s.r) {}

HSphere::HSphere(HVector p, float r): p(p), r(r) {}
