#include "HComplex.h"

HComplex::HComplex() {}

HComplex::HComplex(float a, float b) : re(a), im(b) {}

HComplex::HComplex(const float f[2]) : re(f[0]), im(f[1]) {}

