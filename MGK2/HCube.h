#pragma once
#include <vector>

#include "HVector.h"
class HPlane;

class HCube
{
public:
	std::vector<HPlane> planes;
	double size = 1; // D�ugo�� kraw�dzi

	HCube(int size);
};
