#pragma once
#include <string>
#include <vector>

class HQuat;

class HVector
{
public:
	float x, y, z;

	HVector();
	HVector(float x, float y, float z);
	HVector(const HVector& v);
	HVector(std::vector<float> v);
	HVector(float arr[3]);

	std::string ToString() const;

	HVector& operator=(const HVector &v);

	bool operator==(const HVector &v);
	bool operator!=(const HVector &v);

	HVector operator+(const HVector &v) const;
	HVector operator-(const HVector &v) const;
	void operator+=(const HVector &v);
	void operator-=(const HVector &v);

	HVector operator*(float f) const;
	HVector operator/(float f) const;
	void operator*=(float f);
	void operator/=(float f);

	void Add(const HVector &v);
	void Sub(const HVector &v);
	void Mul(float f);
	void Div(float f);
	
	float Length() const;
	void Normalize();
	
	static HVector Dot(const HVector& v1, const HVector& v2);
	static float DotProduct(const HVector& v1, const HVector& v2);
	static HVector CrossProduct(const HVector& v1, const HVector& v2);
	static float AngleBetween(const HVector& v1, const HVector& v2);

	// Rotate vector using quat
	void RotateQuat(const HQuat& q);

/*
	float GetX() const;
	float GetY() const;
	float GetZ() const;

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

private:
	float x, y, z;
*/
};
