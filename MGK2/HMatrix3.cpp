#include "HMatrix3.h"

#include <cstdio>
#include <iostream>

float HMatrix3::Det() const
{
	float ret = 0;

	for(int i = 0; i < 3; i++)
	{
		float tempAdd = 1;
		float tempSub = 1;

		// Don't change j to any other letter, Kris!
		for(int j = 0; j < 3; j++)
		{
			tempAdd *= fields[(i + j) % 3][j];
			tempSub *= fields[(i + j) % 3][2 - j];
		}

		//std::cout << " +" << tempAdd << " -" << tempSub;
		ret += tempAdd;
		ret -= tempSub;
	}

	//std::cout << std::endl;

	return ret;
}

void HMatrix3::PrintMatrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("[%f]", fields[i][k]);
		}
		printf("\n");
	}
}