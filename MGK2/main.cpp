#include "HVector.h"
#include "HMatrix4.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	// Sprawdzamy przemiennosc dodawania wektorow
	{
		HVector v1(1, 2, 3);
		const HVector v2(4, 5, 6);

		const HVector sum1 = v1 + v2;
		HVector sum2 = HVector(v2);
		sum2.Add(v1);
	
		std::cout << "v1 + v2 = " << sum1.ToString() << "\nv2 + v1 = " << sum2.ToString() << "\n\n";
	}
	
	// Szukamy kat miedzy wektorami [0, 3, 0] i [5, 5, 0]
	{
		const HVector v1(0, 3, 0);
		const HVector v2(5, 5, 0);

		const float angle = HVector::AngleBetween(v1, v2);
		std::cout << "Kat pomiedzy wektorami [0, 3, 0] i [5, 5, 0] wyrazony w radianach: " << angle << "\n\n";
	}

	// Znajdujemy wektor prostopadly do [4, 5, 1] i [4, 1, 3]
	{
		const HVector v1(4, 5, 1);
		const HVector v2(4, 1, 3);

		HVector perpendicular = HVector::CrossProduct(v1, v2);
		std::cout << "Wektor prostopadly do wektorow [4, 5, 1] i [4, 1, 3]: " << perpendicular.ToString() << "\n";

		// Normalizacja tego wektora
		perpendicular.Normalize();
		std::cout << "Po znormalizowaniu: " << perpendicular.ToString() << "\n";
	}*/

	//Test mnozenia macierzy
	{

		float val1[16] = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7};
		float val2[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
		HMatrix4 mat1 = HMatrix4(val1);
		std::cout << "Macierz 1:\n";
		mat1.PrintMatrix();
		HMatrix4 mat2 = HMatrix4(val2);
		std::cout << "Macierz 2:\n";
		mat2.PrintMatrix();
		HMatrix4 mat3 = mat1 * mat2;
		std::cout << "\nMacierz powstala w wyniku mnozenia macierzy 1 przez 2:\n";
		mat3.PrintMatrix();
		HMatrix4 mat4 = mat2 * mat1;
		std::cout << "\nMacierz powstala w wyniku mnozenia macierzy 2 przez 1:\n";
		mat4.PrintMatrix();
	}

	return 0;
}
