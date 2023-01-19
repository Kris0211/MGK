#include "HCube.h"

#include "HPlane.h"

HCube::HCube(int size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			// Yes, I REALLY wanted to automate this
			float sign = k % 2 == 0 ? 1 : -1;
			HPlane plane;

			float vec[3] = { 0, 0, 0 };
			vec[i] = sign * size;
			plane.p = HVector(vec);
			vec[i] = sign;
			plane.n = HVector(vec);

			planes.push_back(plane);
		}
	}
}
