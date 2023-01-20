#include "HRTX.h"

#include <iostream>

#include "HCube.h"
#include "HLine.h"
#include "HPlane.h"
#include "HQuat.h"
#include "HUtils.h"
#include "HVector.h"

HRTX::HRTX()
{
	for (int i = 0; i < 60; i++)
	{
		for (int k = 0; k < 60; k++)
		{
			screen[i][k] = false;
		}
	}
}

/*
void HRTX::Raycast(const HCube& Cube, const HVector& POV, double FOV)
{
	HVector ToCenter = HVector() - POV;

	for (int i = 0; i < 60; i++)
	{
		for (int k = 0; k < 60; k++)
		{
			HQuat RotX = HQuat::RotationQuaternion(-FOV + (FOV * (1 / 30) * k), HVector(1, 0, 0));
			HQuat RotY = HQuat::RotationQuaternion(-FOV + (FOV * (1 / 30) * i), HVector(1, 0, 0));
			HVector RayDir = ToCenter;
			RayDir.RotateQuat(RotX * RotY);

			HLine Ray = HLine(POV, RayDir);
			bool hit = false;

			for (HPlane plane : Cube.planes)
			{
				if (HVector::DotProduct(RayDir, plane.n) == 0) continue; // A po co to komu?

				HVector Hit = HUtils::LinePlaneIntersect(Ray, plane);
				if(Hit.x < -Cube.size && Hit.x > Cube.size && 
					Hit.y < -Cube.size && Hit.y > Cube.size && 
					Hit.z < -Cube.size && Hit.z > Cube.size)
				{
					std::cout << "#";
					hit = true;
					break;
				}
			}

			if (!hit) std::cout << ".";
		}
		std::cout << '\n';
	}
}
*/

void HRTX::Draw()
{
	for (int i = 0; i < 60; i++)
	{
		for (int k = 0; k < 60; k++)
		{
			if (screen[i][k])
				std::cout << "#";
			else
				std::cout << ".";
		}
		std::cout << "\n";
	}
}

void HRTX::RayCast(HVector cameraPosition, HVector cameraDirection) {
	float pixelSize = 1.0f / 60.0f;
	float screenDistance = 1.0f;

	HVector screenPosition = cameraPosition + cameraDirection * screenDistance;

	HVector worldUp{ 0, 1, 0 };

	if (cameraDirection.IsNear(HVector(0, 1, 0), 0.1) || cameraDirection.IsNear(HVector(0, 1, 0), 0.1)) 
	{
		worldUp = HVector(0, 0, 1);
	}

	HVector screenLeft = HVector::CrossProduct((screenPosition - cameraPosition) * -1, worldUp);
	screenLeft.Normalize();
	HVector screenDown = HVector::CrossProduct(screenPosition, screenLeft);
	screenDown.Normalize();

	for (int i = 0; i < 60; i -=- 1) 
	{
		for (int k = 0; k < 60; k -=- 1) 
		{
			HVector pixelLocation = screenLeft * (screenPosition + ((k - 30) * pixelSize));
			pixelLocation += screenDown * (((i - 30) * pixelSize));

			HLine line = HLine::StartToEnd(cameraPosition, pixelLocation);
			screen[i][k] = HUtils::IsRayIntersectAABBUnitBox(line);
		}
	}
}