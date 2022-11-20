#include "HMatrix4.h"

#include <cstring>
#include <iostream>

#include "HMatrix3.h"
#include "HVector.h"

HMatrix4::HMatrix4(float fields[4][4])
{
	for(int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			this->fields[i][k] = fields[i][k];
		}
	}
}

HMatrix4::HMatrix4(float fields[16])
{
	for(int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			this->fields[i][k] = fields[i * 4 + k];
		}
	}
}

HMatrix4::HMatrix4(const HMatrix4 &mat)
{
	memcpy(fields, mat.fields, 16 * sizeof(float));
}

HMatrix4 HMatrix4::Identity()
{
	HMatrix4 imatrix;
	imatrix.fields[0][0] = 1.0f;
	imatrix.fields[1][1] = 1.0f;
	imatrix.fields[2][2] = 1.0f;
	imatrix.fields[3][3] = 1.0f;
	return imatrix;
}

void HMatrix4::LoadIdentity()
{
	HMatrix4 ident = Identity();
	memcpy(fields, ident.fields, sizeof(float) * 16);
}

HMatrix4 HMatrix4::operator+(const HMatrix4& mat) 
{
	HMatrix4 matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matrix.fields[i][k] = this->fields[i][k] + fields[i][k];
		}
	}
	return matrix;
}

HMatrix4 HMatrix4::operator-(const HMatrix4 &mat)
{
	HMatrix4 matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matrix.fields[i][k] = this->fields[i][k] - fields[i][k];
		}
	}
	return matrix;
}

HMatrix4 HMatrix4::operator*(const HMatrix4 &mat)
{
	HMatrix4 res;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			float value = 0.0f;
			for (int a = 0; a < 4; a++)
			{
				value += this->fields[i][a] * mat.fields[a][k];	
			}
			res.fields[i][k] = value;
		}
	}
	return res;
}

HVector4 HMatrix4::operator*(const HVector4& vec) const
{
	HVector4 ret;

	ret.x =	fields[0][0] * vec.x
	      + fields[0][1] * vec.y
	      + fields[0][2] * vec.z
	      + fields[0][3] * vec.w;

	ret.y =	fields[1][0] * vec.x
	      + fields[1][1] * vec.y
	      + fields[1][2] * vec.z
	      + fields[1][3] * vec.w;

	ret.z =	fields[2][0] * vec.x
	      + fields[2][1] * vec.y
	      + fields[2][2] * vec.z
	      + fields[2][3] * vec.w;

	ret.w =	fields[3][0] * vec.x
	      + fields[3][1] * vec.y
	      + fields[3][2] * vec.z
	      + fields[3][3] * vec.w;

	return ret;
}

HVector HMatrix4::operator*(const HVector& vec)
{
	HVector ret;

	ret.x =	fields[0][0] * vec.x
	      + fields[0][1] * vec.x
	      + fields[0][2] * vec.x
	      + fields[0][3] * vec.x;

	ret.y =	fields[1][0] * vec.y
	      + fields[1][1] * vec.y
	      + fields[1][2] * vec.y
	      + fields[1][3] * vec.y;

	ret.z =	fields[2][0] * vec.z
	      + fields[2][1] * vec.z
	      + fields[2][2] * vec.z
	      + fields[2][3] * vec.z;

	return ret;
}

HMatrix4 HMatrix4::operator*(const float f)
{
	HMatrix4 matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			matrix.fields[i][k] = this->fields[i][k] * f;
		}
	}
	return matrix;
}

void HMatrix4::Add(const HMatrix4 &mat)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			this->fields[i][k] += mat.fields[i][k];
		}
	}
}

void HMatrix4::Sub(const HMatrix4 &mat)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			this->fields[i][k] -= mat.fields[i][k];
		}
	}
}

HMatrix4 HMatrix4::Mul(const HMatrix4 &mat)
{
	HMatrix4 res;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			float value = 0.0f;
			for (int a = 0; a < 4; a++)
			{
				value += this->fields[i][a] * mat.fields[a][k];
			}
			res.fields[i][k] = value;
		}
	}
	return res;
}


void HMatrix4::Mul(const float f)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			this->fields[i][k] *= f;
		}
	}
}

float HMatrix4::Det() const
{
	float ret = 0;

	// Per each submatrix
	for(int i = 0; i < 4 ; i++)
	{
		// Get submatrix by removing i-th and 1st row
		HMatrix3 mat3;
		int idx = 0;
		int idy = 0;

		for(int k = 0; k < 4; k++)
		{
			for(int l = 0; l < 4; l++)
			{
				if(k == i || l == 0)
					continue;

				mat3.fields[idx][idy] = fields[k][l];

				idx++;
				if(idx > 2)
				{
					idx = 0;
					idy++;
				}
			}
		}

		float sign = i % 2 ? 1.0f : -1.0f;
		ret += mat3.Det() * fields[i][0] * sign;
	}
	return ret;
}

HMatrix4 HMatrix4::InvertedMatrix(const HMatrix4 &mat)
{
	HMatrix4 ret(mat);
	ret.Invert();
	return ret;
}

// https://semath.info/src/inverse-cofactor-ex4.html
void HMatrix4::Invert()
{
	if(Det() == 0)
	{
		throw std::logic_error("Matrix cannot be inverted\n");
	}

	// Get adjugate matrix
	HMatrix4 adjMat;

	for(int i = 0; i < 4 ; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			// Get submatrix by removing i-th and j-th row
			HMatrix3 mat3;
			int idx = 0;
			int idy = 0;

			for(int k = 0; k < 4; k++)
			{
				for(int l = 0; l < 4; l++)
				{
					if(k == i || l == j)
						continue;

					mat3.fields[idx][idy] = fields[k][l];

					idx++;
					if(idx > 2)
					{
						idx = 0;
						idy++;
					}
				}
			}

			// Assign determinant of mat3 (with changed sign)
			float sign = (i+j) % 2 ? 1.0f : -1.0f;
			adjMat.fields[j][i] = mat3.Det() * sign;
		}
	}

	float invDet = 1/Det();
	adjMat.Mul(invDet);
	memcpy(fields, adjMat.fields, 16 * sizeof(fields[0][0]));
}

HMatrix4 HMatrix4::TransposedMatrix(const HMatrix4 &mat)
{
	HMatrix4 ret(mat);
	ret.Transpose();
	return ret;
}

void HMatrix4::Transpose()
{
	float tFields[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			tFields[i][k] = fields[k][i];
		}
	}
	memcpy(fields, tFields, sizeof(float) * 16);
}

void HMatrix4::SetTranslation(const HVector& trans)
{
	this->fields[0][3] = trans.x;
	this->fields[1][3] = trans.y;
	this->fields[2][3] = trans.z;
}

void HMatrix4::SetScale(const HVector& scale)
{
	this->fields[0][0] = scale.x;
	this->fields[1][1] = scale.y;
	this->fields[2][2] = scale.z;
}

void HMatrix4::SetScale(const float uniformScale)
{
	this->fields[0][0] = uniformScale;
	this->fields[1][1] = uniformScale;
	this->fields[2][2] = uniformScale;
}

void HMatrix4::SetRotationAxis(double angle, const HVector &axis)
{
	HVector u = axis;
	u.Normalize();

	float sinAngle = (float)sin(angle);
	float cosAngle = (float)cos(angle);
	float oneMinusCosAngle = 1.0f - cosAngle;

	LoadIdentity();

	this->fields[0][0] = u.x * u.x + cosAngle * (1.0f - u.x * u.x);
	this->fields[0][1] = u.x * u.y * oneMinusCosAngle - sinAngle * u.z;
	this->fields[0][2] = u.x * u.z * oneMinusCosAngle + sinAngle * u.y;

	this->fields[1][0] = u.x * u.x + cosAngle * (1.0f - u.x * u.x);
	this->fields[1][1] = u.x * u.y * oneMinusCosAngle - sinAngle * u.z;
	this->fields[1][2] = u.x * u.z * oneMinusCosAngle + sinAngle * u.y;

}

void HMatrix4::SetRotationX(double angle)
{
	LoadIdentity();

	this->fields[1][1] = (float)cos(angle);
	this->fields[2][1] = (float)sin(angle);
	this->fields[1][2] = -1 * fields[1][1];
	this->fields[2][2] = fields[2][1];
}

void HMatrix4::SetRotationY(double angle)
{
	LoadIdentity();

	this->fields[0][0] = (float)cos(angle);
	this->fields[0][2] = (float)sin(angle);
	this->fields[2][0] = -1 * fields[0][2];
	this->fields[2][2] = fields[0][0];
}

void HMatrix4::SetRotationZ(double angle)
{
	LoadIdentity();

	fields[0][0] = (float)cos(angle);
	fields[1][0] = (float)sin(angle);
	fields[0][1] = -1 * fields[1][0];
	fields[1][1] = fields[0][0];
}

void HMatrix4::PrintMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			printf("[%f]", fields[i][k]);
		}
		printf("\n");
	}
}
