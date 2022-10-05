#pragma once
#include <string>

class HVector
{
public:
	float x, y, z;
	HVector();
	HVector(float x, float y, float z);
	HVector(const HVector& v);
	~HVector();

	const std::string ToString() const;

	HVector operator+(const HVector& v);
	HVector operator-(const HVector& v);
	void operator+=(const HVector& v);
	void operator-=(const HVector& v);

	HVector operator*(float f);
	HVector operator/(float f);
	void operator*=(float f);
	void operator/=(float f);

	void Add(HVector v);
	void Sub(HVector v);
	void Mul(float f);
	void Div(float f);
	
	float Length() const;
	void Normalize();
	
	static HVector Dot(const HVector& v1, const HVector& v2);
	static float DotProduct(const HVector& v1, const HVector& v2);
	static HVector CrossProduct(const HVector& v1, const HVector& v2);
	static float AngleBetween(const HVector& v1, const HVector& v2);
	
};
