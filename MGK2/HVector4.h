#pragma once
#include <string>

#include "HVector.h"

class HVector4
{
public:
	float x, y, z, w;

	HVector4();
	HVector4(float x, float y, float z);
	HVector4(float x, float y, float z, float w);
	HVector4(const HVector4& v);
	HVector4(const HVector& v);

	std::string ToString() const;

	HVector4& operator=(const HVector4 &v);

	HVector4 operator+(const HVector4 &v) const;
	HVector4 operator-(const HVector4 &v) const;
	void operator+=(const HVector4 &v);
	void operator-=(const HVector4 &v);

	HVector4 operator*(float f) const;
	HVector4 operator/(float f) const;
	void operator*=(float f);
	void operator/=(float f);

	void Add(const HVector4 &v);
	void Sub(const HVector4 &v);
	void Mul(float f);
	void Div(float f);
	
	float Length() const;
	void Normalize();
};
