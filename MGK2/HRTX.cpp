#include "HRTX.h"

#include <iostream>

#include "HCube.h"
#include "HLine.h"
#include "HPlane.h"
#include "HQuat.h"
#include "HUtils.h"
#include "HVector.h"

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
