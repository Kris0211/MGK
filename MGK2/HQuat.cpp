#include "HQuat.h"

#include <cstring>

HQuat::HQuat() {}

HQuat::HQuat(float a, float b, float c, float d) : re(a), im(b, c, d) {}

HQuat::HQuat(const float f[4]) : re(f[0]), im(f[1], f[2], f[3]) {}

HQuat::HQuat(float a, const HVector& v) : re(a), im(v) {}

HQuat::HQuat(const HVector4& v) : re(v.x), im(v.y, v.z, v.w) {}

HQuat HQuat::operator+(const HQuat& q) const
{
	return HQuat(re + q.re, im + q.im);
}

HQuat HQuat::operator-(const HQuat& q) const
{
	return HQuat(re - q.re, im - q.im);
}

HQuat HQuat::operator*(const HQuat& q) const
{
	return HQuat(
		re * q.re - HVector::DotProduct(im, q.im),
		q.im * re + im * q.re + HVector::CrossProduct(im, q.im)
		);
}

HQuat HQuat::operator/(const HQuat& q) const
{
}

void HQuat::operator+=(const HQuat& q)
{
	re += q.re; im += q.im;
}

void HQuat::operator-=(const HQuat& q)
{
	re -= q.re; im -= q.im;
}

void HQuat::operator*=(const HQuat& q)
{
	re = re * q.re - HVector::DotProduct(im, q.im);
	im = q.im * re + im * q.re + HVector::CrossProduct(im, q.im);
}

void HQuat::operator/=(const HQuat& q)
{
}

void HQuat::Add(const HQuat& q)
{
	*this += q;
}

void HQuat::Sub(const HQuat& q)
{
	*this -= q;
}

void HQuat::Mul(const HQuat& q)
{
	*this *= q;
}

void HQuat::Div(const HQuat& q)
{
	*this /= q;
}

float HQuat::Re() const
{
}

HVector HQuat::Im() const
{
}

HQuat HQuat::Conjugate()
{
}

HQuat HQuat::GetConjugate(const HQuat& q)
{
}

float HQuat::Magnitude() const
{
}

HQuat HQuat::GetMagnitude(const HQuat& q)
{
}

