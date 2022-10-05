#include "HVector.h"
#include <cmath>
#include <stdexcept>
#include <sstream>

HVector::HVector() : x(0), y(0), z(0)
{
}

HVector::HVector(float x, float y, float z): x(x), y(y), z(z)
{
}

HVector::HVector(const HVector& v): x(v.x), y(v.y), z(v.z)
{
}

HVector::~HVector()
{
}

const std::string HVector::ToString() const
{
	std::stringstream ss;
	ss << "[" << this->x << ", " << this->y << ", " << this->z << "]";
	return ss.str();
}

HVector HVector::operator+(const HVector& v)
{
	return HVector(x + v.x, y + v.y, z + v.z);
}

HVector HVector::operator-(const HVector& v)
{
	return HVector(x - v.x, y - v.y, z - v.z);
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

HVector HVector::operator*(float f)
{
	return HVector(x * f, y * f, z * f);
}

HVector HVector::operator/(float f)
{
	if (f != 0.0f)
	{
		f = 1 / f;
		return HVector(x * f, y * f, z * f);
	}
	else 
	{
		throw std::runtime_error("Math erorr: Cannot divide by zero\n");
	}
}

void HVector::operator*=(float f)
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
		throw std::runtime_error("Math erorr: Cannot divide by zero\n");
	}
}

 void HVector::Add(HVector v)
 {
	 this->x += v.x;
	 this->y += v.y;
	 this->z += v.z;
 }

 void HVector::Sub(HVector v)
 {
	 this->x -= v.x;
	 this->y -= v.y;
	 this->z -= v.z;
 }

 void HVector::Mul(float f)
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
	 else throw std::runtime_error("Math erorr: Cannot divide by zero\n"); 
 }

 float HVector::Length() const
 {
	 return (float)sqrt(
		 (this->x * this->x) + 
		 (this->y * this->y) + 
		 (this->z * this->z));
 }

 void HVector::Normalize() 
 {
	 float n = this->Length();
	 if (n != 0) this->Div(n);
	 else throw std::runtime_error("Math erorr: Cannot divide by zero\n");
 }

 HVector HVector::Dot(const HVector& v1, const HVector& v2)
 {
	 HVector vect;
	 vect.x = v1.x * v2.x;
	 vect.y = v1.y * v2.y;
	 vect.z = v1.z * v2.z;
	 return vect;
 }

 float HVector::DotProduct(const HVector& v1, const HVector& v2)
 {
	 HVector vect;
	 vect.x = v1.x * v2.x;
	 vect.y = v1.y * v2.y;
	 vect.z = v1.z * v2.z;
	 return vect.x + vect.y + vect.z;
 }

 HVector HVector::CrossProduct(const HVector& v1, const HVector& v2)
 {
	 return HVector(
		 v1.y * v2.z - v1.z * v2.y,
		 v1.z * v2.x - v1.x * v2.z,
		 v1.x * v2.y - v1.y * v2.x);
 }

float HVector::AngleBetween(const HVector& v1, const HVector& v2) 
{
	return acos(HVector::DotProduct(v1, v2) / (v1.Length() * v2.Length()));
}
