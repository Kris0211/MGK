#pragma once
class HVector;

class HMatrix4
{
public:
	float fields[4][4] = {{0.0f}};

	HMatrix4() = default;
	explicit HMatrix4(float fields[4][4]);
	explicit HMatrix4(float fields[16]);
	HMatrix4(const HMatrix4 &mat);
	~HMatrix4() = default;
	
	static HMatrix4 Identity();
	void LoadIdentity();

	HMatrix4 operator+(const HMatrix4 &mat);
	HMatrix4 operator-(const HMatrix4 &mat);
	HMatrix4 operator*(float f);
	HMatrix4 operator*(const HMatrix4 &mat);

	void Add(const HMatrix4& mat);
	void Sub(const HMatrix4& mat);
	void Mul(float f);
	HMatrix4 Mul(const HMatrix4 &mat);

	static HMatrix4 InvertedMatrix(const HMatrix4 &mat);
	void Invert();

	static HMatrix4 TransposedMatrix(const HMatrix4 &mat);
	void Transpose();

	void SetTranslation(const HVector &trans);

	void SetScale(const HVector &scale);
	void SetScale(float uniformScale);

	void SetRotationAxis(double angle, const HVector &axis);
	void SetRotationX(double angle);
	void SetRotationY(double angle);
	void SetRotationZ(double angle);

	void PrintMatrix();

};
