#pragma once

// Helper class for HQuat
class HComplex
{
public:
	float re = 0.0f;
	float im = 0.0f;

	HComplex();
	HComplex(float a, float b);
	HComplex(const float f[2]);
	~HComplex() = default;
};
