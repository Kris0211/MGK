#include "HSphere.h"

HSphere::HSphere(const HSphere& s): c(s.c), r(s.r) {}

HSphere::HSphere(HVector p, float r): c(p), r(r) {}
