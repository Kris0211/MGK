#include "HVector.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

#include "HQuat.h"

HVector::HVector(): x(0), y(0), z(0)
{}

HVector::HVector(const float x, const float y, const float z): x(x), y(y), z(z)
{}

HVector::HVector(const HVector& v): x(v.x), y(v.y), z(v.z)
{}

HVector::HVector(std::vector<float> v) : x(v[0]), y(v[1]), z(v[2])
{}

HVector::HVector(float arr[3]) : x(arr[0]), y(arr[1]), z(arr[2]) {}

std::string HVector::ToString() const
{
	std::stringstream ss;
	ss << "[" << this->x << ", " << this->y << ", " << this->z << "]";
	return ss.str();
}

HVector& HVector::operator=(const HVector& v) = default;

bool HVector::operator==(const HVector& v) const
{
	return x == v.x && y == v.y && z ==v.z;
}

bool HVector::operator!=(const HVector& v) const
{
	return x != v.x || y != v.y || z != v.z;
}

HVector HVector::operator+(const HVector& v) const
{
	return {x + v.x, y + v.y, z + v.z};
}

HVector HVector::operator-(const HVector& v) const
{
	return {x - v.x, y - v.y, z - v.z};
}

void HVector::operator+=(const HVector& v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

void HVector::operator-=(const HVector& v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

HVector HVector::operator+(float f) const
{
	return { x + f, y + f, z + f };
}

HVector HVector::operator-(float f) const
{
	return { x - f, y - f, z - f };
}


void HVector::operator+=(float f)
{
	this->x += f;
	this->y += f;
	this->z += f;
}

void HVector::operator-=(float f)
{
	this->x -= f;
	this->y -= f;
	this->z -= f;
}

HVector HVector::operator*(const float f) const
{
	return {x * f, y * f, z * f};
}

HVector HVector::operator/(float f) const
{
	if (f != 0.0f)
	{
		f = 1 / f;
		return {x * f, y * f, z * f};
	}
	throw std::logic_error("Math error: Cannot divide by zero\n");
}

void HVector::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;
}

void HVector::operator/=(float f)
{
	if (f != 0.0f)
	{
		f = 1 / f;
		x *= f;
		y *= f;
		z *= f;
	}
	else 
	{
		throw std::logic_error("Math error: Cannot divide by zero\n");
	}
}

HVector HVector::operator*(const HVector& v) const
{
	return { this->x * v.x, this->y * v.y, this->z * v.z };
}

HVector HVector::operator/(const HVector& v) const
{
	return { this->x / v.x, this->y / v.y, this->z / v.z };
}

HVector HVector::operator-()
{
	HVector vec;
	vec.x = -this->x;
	vec.y = -this->y;
	vec.z = -this->z;
	return vec;
}

void HVector::Add(const HVector &v)
 {
	 this->x += v.x;
	 this->y += v.y;
	 this->z += v.z;
 }

 void HVector::Sub(const HVector& v)
 {
	 this->x -= v.x;
	 this->y -= v.y;
	 this->z -= v.z;
 }

 void HVector::Mul(const float f)
 {
	 this->x *= f;
	 this->y *= f;
	 this->z *= f;
 }

 void HVector::Div(float f)
 {
	 if (f != 0) 
	 {
		 f = 1 / f;
		 this->x *= f;
		 this->y *= f;
		 this->z *= f;
	 }
	 else
	 {
		 throw std::logic_error("Math error: Cannot divide by zero\n");
	 }
 }

 float HVector::Length() const
 {
	 return sqrt(
		 this->x * this->x + 
		 this->y * this->y + 
		 this->z * this->z);
 }

 void HVector::Normalize() 
 {
	 const float n = this->Length();
	 if (n != 0.0f) this->Div(n);
	 else throw std::logic_error("Math error: Cannot divide by zero\n");
 }

HVector HVector::Normal()
{
	const float len = this->Length();
	if (len == 0.0f) return {0, 0, 0};
	return *this / len;
}

 bool HVector::IsNear(const HVector &vec, float tolerance) const
 {
	 return std::abs(this->Length() - vec.Length()) < tolerance;
 }

 HVector HVector::Dot(const HVector& v1, const HVector& v2)
 {
	 return { v1.x * v2.x,
	 		v1.y * v2.y,
	 		v1.z * v2.z };
 }

 float HVector::DotProduct(const HVector& v1, const HVector& v2)
 {
	 return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
 }

 HVector HVector::CrossProduct(const HVector& v1, const HVector& v2)
 {
	 return {
		 v1.y * v2.z - v1.z * v2.y,
		 v1.z * v2.x - v1.x * v2.z,
		 v1.x * v2.y - v1.y * v2.x
	 };
 }

float HVector::AngleBetween(const HVector& v1, const HVector& v2) 
{
	return acos(DotProduct(v1, v2) / (v1.Length() * v2.Length()));
}

void HVector::RotateQuat(const HQuat& q)
{
	// Convert to quat
	HQuat p(0.0f, x, y, z);

	// Rotate
	p = HQuat::Inverted(q) * p * q;

	// Convert back to vector
	x = p.im.x;
	y = p.im.y;
	z = p.im.z;
}

HVector HVector::Min(HVector a, HVector b) {
    HVector result;
    result.x = std::min(a.x, b.x);
    result.y = std::min(a.y, b.y);
    result.z = std::min(a.z, b.z);
    return result;
}

HVector HVector::Max(HVector a, HVector b) {
    HVector result;
    result.x = std::max(a.x, b.x);
    result.y = std::max(a.y, b.y);
    result.z = std::max(a.z, b.z);
    return result;
}

/*
float HVector::GetX() const { return x; }

float HVector::GetY() const { return y; }

float HVector::GetZ() const { return z; }

void HVector::SetX(const float x) { this->x = x; }

void HVector::SetY(const float y) { this->y = y; }

void HVector::SetZ(const float z) { this->z = z; }
*/
