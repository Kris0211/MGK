#include "HVector4.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

HVector4::HVector4(): x(0), y(0), z(0), w(0) {}

HVector4::HVector4(const float x, const float y, const float z) : x(x), y(y), z(z), w(0) {}

HVector4::HVector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

HVector4::HVector4(const HVector4& v): x(v.x), y(v.y), z(v.z), w(v.w) {}

HVector4::HVector4(const HVector& v) : x(v.x), y(v.y), z(v.z), w(0) {}

std::string HVector4::ToString() const
{
	std::stringstream ss;
	ss << "[" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << "]";
	return ss.str();
}

HVector4& HVector4::operator=(const HVector4& v) = default;

HVector4 HVector4::operator+(const HVector4& v) const
{
	return {x + v.x, y + v.y, z + v.z, w + v.w};
}

HVector4 HVector4::operator-(const HVector4& v) const
{
	return {x - v.x, y - v.y, z - v.z, w - v.w};
}

void HVector4::operator+=(const HVector4& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	this->w += v.w;
}

void HVector4::operator-=(const HVector4& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	this->w -= v.w;
}

HVector4 HVector4::operator*(const float f) const
{
	return {x * f, y * f, z * f, w * f};
}

HVector4 HVector4::operator/(float f) const
{
	if (f != 0.0f)
	{
		f = 1 / f;
		return {x * f, y * f, z * f, w * f};
	}
	throw std::logic_error("Math error: Cannot divide by zero\n");
}

void HVector4::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
}

void HVector4::operator/=(float f)
{
	if (f != 0.0f)
	{
		f = 1 / f;
		x *= f;
		y *= f;
		z *= f;
		w *= f;
	}
	else 
	{
		throw std::logic_error("Math error: Cannot divide by zero\n");
	}
}

 void HVector4::Add(const HVector4 &v)
 {
	 this->x += v.x;
	 this->y += v.y;
	 this->z += v.z;
	 this->w -= v.w;
 }

 void HVector4::Sub(const HVector4& v)
 {
	 this->x -= v.x;
	 this->y -= v.y;
	 this->z -= v.z;
	 this->w -= v.w;
 }

 void HVector4::Mul(const float f)
 {
	 this->x *= f;
	 this->y *= f;
	 this->z *= f;
	 this->w *= f;
 }

 void HVector4::Div(float f)
 {
	 if (f != 0) 
	 {
		 f = 1 / f;
		 this->x *= f;
		 this->y *= f;
		 this->z *= f;
	 	 this->w *= f;
	 }
	 else
	 {
		 throw std::logic_error("Math error: Cannot divide by zero\n");
	 }
 }

 float HVector4::Length() const
 {
	 return sqrt(
		 this->x * this->x + 
		 this->y * this->y + 
		 this->z * this->z +
		 this->w * this->w);
 }

 void HVector4::Normalize() 
 {
	 const float n = this->Length();
	 if (n != 0) this->Div(n);
	 else throw std::logic_error("Math error: Cannot divide by zero\n");
 }

 