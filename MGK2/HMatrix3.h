#pragma once

// Not fully implemented
// Used as helper class
class HMatrix3
{
public:

	float fields[3][3] = {{0.0f}};

	HMatrix3() = default;

	float Det() const;
	void PrintMatrix();
};
