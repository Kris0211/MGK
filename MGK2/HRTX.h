#pragma once

// Wow so much next-gen!
// Requires at least nvidia RXT 2137 VI Tiger to handle that much next-gen

class HCube;
class HVector;

class HRTX
{

public:

	static void Raycast(const HCube& Cube, const HVector& POV, double FOV); // That's all folks!
};
