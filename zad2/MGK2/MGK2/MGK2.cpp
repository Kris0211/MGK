﻿// MGK2.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "MGK2.h"
#include "HVector.h"

using namespace std;

int main()
{
	// Sprawdzamy przemienność dodawania wektorów
	{
		HVector v1(1, 2, 3);
		HVector v2(4, 5, 6);

		HVector sum1 = v1 + v2;
		HVector sum2 = HVector(v2);
		sum2.Add(v1);
	
		std::cout << "v1 + v2 = " << sum1.ToString() << "\nv2 + v1 = " << sum2.ToString() << "\n";
	}
	
	// Szukamy kata miedzy wektorami [0, 3, 0] i [5, 5, 0]
	{
		HVector v1(0, 3, 0);
		HVector v2(5, 5, 0);

		float angle = HVector::AngleBetween(v1, v2);
		std::cout << "Kat pomiedzy wektorami [0, 3, 0] i [5, 5, 0]: " << angle << endl;
	}

	// Znajdujemy wektor prostopadly do [4, 5, 1] i [4, 1, 3]
	{
		HVector v1(4, 5, 6);
		HVector v2(4, 1, 3);

		HVector perpendicular = HVector::CrossProduct(v1, v2);
		std::cout << "Wektor prostopadly do wektorow [4, 5, 1] i [4, 1, 3]: " << perpendicular.ToString();

		// Normalizacja tego wektora
		perpendicular.Normalize();
		std::cout << "Po znormalizowaniu: " << perpendicular.ToString();
	}

	return 0;
}
