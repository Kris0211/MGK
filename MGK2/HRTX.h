#pragma once

// Wow so much next-gen!
// Requires at least nvidia RXT 2137 VI Tiger to handle that much next-gen

class HCube;
class HVector;

class HRTX
{
public:
	HRTX();

	//void Raycast(const HCube &Cube, const HVector &CameraPos, double FOV);
	void Draw();
	void RayCast(HVector cameraPosition, HVector cameraDirection);

private:
	bool screen[60][60] = {{false}};
};
