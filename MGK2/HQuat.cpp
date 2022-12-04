#include "HQuat.h"

#include <sstream>
#include <stdexcept>

HQuat::HQuat() {}

HQuat::HQuat(float a, float i, float j, float k) : re(a), im(i, j, k) {}

HQuat::HQuat(const float f[4]) : re(f[0]), im(f[1], f[2], f[3]) {}

HQuat::HQuat(float a, const HVector& v) : re(a), im(v) {}

HQuat::HQuat(const HVector4& v) : re(v.x), im(v.y, v.z, v.w) {}

HQuat HQuat::RotationQuaternion(double angle, const HVector& axis)
{
	HVector normAxis = axis;
	normAxis.Normalize();
	normAxis *= (float)sin(angle * 0.5);
	return HQuat((float)cos(angle * 0.5), normAxis);
}

std::string HQuat::ToString() const
{
	std::stringstream ss;
	ss << "(" << re << ", " << im.x << ", " << im.y << ", " << im.z <<  ")";
	return ss.str();
}

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
	float denominator = q.re * q.re + HVector::DotProduct(q.im, q.im);
	if(denominator != 0)
	{
		return HQuat(
			(re * q.re + HVector::DotProduct(im, q.im)) / denominator,
			(q.im * -re + im * q.re - HVector::CrossProduct(im, q.im)) / denominator
		);
	}
	else throw std::logic_error("Cannot divide quat!");
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
	float denominator = q.re * q.re + HVector::DotProduct(q.im, q.im);
	if(denominator != 0)
	{
		re = (re * q.re + HVector::DotProduct(im, q.im)) / denominator;
		im = (q.im * -re + im * q.re - HVector::CrossProduct(im, q.im)) / denominator;
	}
	else throw std::logic_error("Cannot divide quat!");
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
	return re;
}

HVector HQuat::Im() const
{
	return im;
}

void HQuat::Invert()
{
	if(re != 0 && im != HVector())
	{
		//TODO: Implement me pls
	}
	else std::logic_error("Cannot invert quat!");
}

HQuat HQuat::Inverted(const HQuat& q)
{
	HQuat ret = q;
	ret.Invert();
	return ret;
}

void HQuat::Conjugate()
{
	im *= -1;
}

HQuat HQuat::GetConjugate(const HQuat& q)
{
	HQuat ret = q;
	ret.im *= -1;
	return ret;
}

float HQuat::Magnitude() const
{
	return (float)sqrt(
		re * re + 
		im.x * im.x +
		im.y * im.y +
		im.z * im.z
	);
}

float HQuat::GetMagnitude(const HQuat& q)
{
	return q.Magnitude();
}
