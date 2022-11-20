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


	// [ MACIERZE ] //
	float val1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	float val2[16] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7 };
	float val3[16] = { 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1};
	HMatrix4 mat1 = HMatrix4(val1);
	std::cout << "Macierz 1:\n";
	mat1.PrintMatrix();
	HMatrix4 mat2 = HMatrix4(val2);
	std::cout << "Macierz 2:\n";
	mat2.PrintMatrix();

	//Operacje na macierzach
	{
		mat1.Add(mat2);
		std::cout << "\nSuma macierzy:\n";
		mat1.PrintMatrix();

		mat1 = HMatrix4(val1);
		mat1.Sub(mat2);
		std::cout << "\nRoznica macierzy:\n";
		mat1.PrintMatrix();

		mat1 = HMatrix4(val1);
		mat1.Mul(5);
		std::cout << "\nWynik mnozenia macierzy 1 przez 5:\n";
		mat1.PrintMatrix();

		mat1 = HMatrix4(val1);
		mat1.Transpose();
		std::cout << "\nTranspozycja macierzy 1:\n";
		mat1.PrintMatrix();
		
		mat1 = HMatrix4(val3);
		mat1.Invert();
		std::cout << "\nMacierz odwrotna do macierzy 1:\n";
		mat1.PrintMatrix();
		
		mat1.LoadIdentity();
		std::cout << "\nMacierz jednostkowa:\n";
		mat1.PrintMatrix();

		HVector vect = HVector(5, 10, 15);

		mat1.SetTranslation(vect);
		std::cout << "\nMacierz translacji o wektor [5, 10, 15]:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetScale(vect);
		std::cout << "\nMacierz skalowania o skali rownej wektorowi [5, 10, 15]:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetScale(3);
		std::cout << "\nMacierz skalowania o stalej skali rownej 3:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationX(30.0);
		std::cout << "\nMacierz obrotu wokol osi X o 30 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationY(45.0);
		std::cout << "\nMacierz obrotu wokol osi Y o 45 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationZ(60.0);
		std::cout << "\nMacierz obrotu wokol osi Z o 60 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationAxis(90.0, vect);
		std::cout << "\nMacierz obrotu wokol osi:\n";
		mat1.PrintMatrix();
	}

	//Test (braku) przemiennosci mnozenia macierzy
	{
		std::cout << "\n\n-=:BRAK PRZEMIENNOSCI MNOZENIA MACIERZY:=-";
		mat1 = HMatrix4(val1);
		mat2 = HMatrix4(val2);
		HMatrix4 mat3 = mat1 * mat2;
		std::cout << "\nMacierz powstala w wyniku mnozenia macierzy 1 przez macierz 2:\n";
		mat3.PrintMatrix();
		HMatrix4 mat4 = mat2 * mat1;
		std::cout << "\nMacierz powstala w wyniku mnozenia macierzy 2 przez macierz 1:\n";
		mat4.PrintMatrix();
	}

	return 0;
}
