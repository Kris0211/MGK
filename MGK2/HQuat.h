#pragma once
#include "HVector.h"
#include "HVector4.h"


class HQuat
{
public:
	// Vector representation is most usefull ig
	float re;
	HVector im;

	HQuat();
	HQuat(float a, float i, float j, float k);
	HQuat(const float f[4]);
	HQuat(float a, const HVector& v);
	HQuat(const HVector4& v);
	~HQuat() = default;

	// Convert angle-axis rotation to quat
	static HQuat RotationQuaternion(double angle, const HVector& axis);

	std::string ToString() const;

	HQuat operator+(const HQuat& q) const;
	HQuat operator-(const HQuat& q) const;
	HQuat operator*(const HQuat& q) const;
	HQuat operator/(const HQuat& q) const;

	void operator+=(const HQuat& q);
	void operator-=(const HQuat& q);
	void operator*=(const HQuat& q);
	void operator/=(const HQuat& q);

	void Add(const HQuat& q);
	void Sub(const HQuat& q);
	void Mul(const HQuat& q);
	void Div(const HQuat& q);

	float Re() const;
	HVector Im() const;

	void Invert();
	static HQuat Inverted(const HQuat& q);

	void Conjugate();
	static HQuat GetConjugate(const HQuat& q);

	float Magnitude() const;
	static float GetMagnitude(const HQuat& q);
};
