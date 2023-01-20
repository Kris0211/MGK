#include "HVector.h"
#include "HMatrix4.h"
#include <iostream>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006 

#define PI_BUT_FUNNY 22/7 

#include "HCube.h"
#include "HLine.h"
#include "HPlane.h"
#include "HQuat.h"
#include "HRTX.h"
#include "HSegment.h"
#include "HSphere.h"
#include "HUtils.h"
#include "HVector4.h"

using namespace std;

int main()
{
	//HCube Cube = HCube(1);

	HRTX raytracer;

	float pitch = 0.33f;
	float yaw = -0.22f;
	float radius = 50.0f;

	HVector camPos(1, 1, 1);
	HVector camDir = camPos * -1.0f;

	const float pitchRadians = pitch * PI / 180.0f;
	const float yawRadians = yaw * PI / 180.0f;
	camPos.x = radius * std::cos(pitchRadians) * std::cos(yawRadians);
	camPos.y = radius * std::sin(pitchRadians) * std::cos(yawRadians);
	camPos.z = radius * std::sin(yawRadians);
	//std::system("cls");
	camDir.Normalize();
	raytracer.RayCast(camPos, camDir);
	raytracer.Draw();

	std::cout << "dupa debugging: " << camPos.ToString() << "\n" << camDir.ToString() << "\n";

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

/*
	// [ MACIERZE ] //
	float val1[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	float val2[16] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7 };
	float val3[16] = { 2, 3, 4, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1};
	HMatrix4 mat1 = HMatrix4(val1);
	std::cout << "Macierz 1:\n";
	mat1.PrintMatrix();
	HMatrix4 mat2 = HMatrix4(val2);
	std::cout << "Macierz 2:\n";
	mat2.PrintMatrix();
	HMatrix4 mat3 = HMatrix4(val3);
	std::cout << "Macierz 3:\n";
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

		// https://www.wolframalpha.com/input?key=&i2d=true&i=%7B%7B2%2C3%2C4%2C-1%7D%2C%7B1%2C1%2C-1%2C1%7D%2C%7B1%2C-1%2C1%2C1%7D%2C%7B-1%2C1%2C1%2C1%7D%7D
		mat1 = HMatrix4(val3);
		mat1.Invert();
		std::cout << "\nMacierz odwrotna do macierzy 3:\n";
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
		mat1.SetRotationX(PI/6);
		std::cout << "\nMacierz obrotu wokol osi X o 30 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationY(PI/4);
		std::cout << "\nMacierz obrotu wokol osi Y o 45 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationZ(PI/3);
		std::cout << "\nMacierz obrotu wokol osi Z o 60 stopni:\n";
		mat1.PrintMatrix();

		mat1.LoadIdentity();
		mat1.SetRotationAxis(PI/2, vect);
		std::cout << "\nMacierz obrotu wokol osi:\n";
		mat1.PrintMatrix();
	}

	//Test obrotu wektora
	{
		std::cout << "\n-=:OBROT WEKTORA:=-";
		mat1.SetRotationY(PI * 0.5);
		HVector4 vec = HVector4(1, 0, 0, 1);
		HVector4 result = mat1 * vec;
		std::cout << "\nWektor [1, 0, 0, 1] po obrocie o 90 stopni wokol osi Y wynosi:\n" << result.ToString();
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
	*/

	/*
	HQuat q1(2, 1, 0, 0);
	HQuat q2(4, 0, 1, 0);

	std::cout << "Kwaternion nr 1: " << q1.ToString() << "\nKwaternion nr 2: " << q2.ToString() << "\n\n";

	// Sprawdzenie operacji na kwaternionach
	{
		std::cout << "=== SPRAWDZENIE OPERACJI NA KWATERNIONACH ==\n\n";

		// Dodawanie
		std::cout << q1.ToString() << " + " << q2.ToString() << " = " << (q1 + q2).ToString() << "\n";

		// Odejmowanie
		std::cout << q1.ToString() << " - " << q2.ToString() << " = " << (q1 - q2).ToString() << "\n";

		// Mnożenie
		std::cout << q1.ToString() << " * " << q2.ToString() << " = " << (q1 * q2).ToString() << "\n";

		// Dzielenie
		std::cout << q1.ToString() << " / " << q2.ToString() << " = " << (q1 / q2).ToString() << "\n";

		// Odwrotność
		std::cout << q1.ToString() << "^-1 = " << HQuat::Inverted(q2).ToString() << "\n";

		// Sprzężenie
		std::cout << "Sprzezenie " << q1.ToString() << " = " << HQuat::GetConjugate(q1).ToString() << "\n";

		// Moduł
		std::cout << "Norma " << q1.ToString() << " = " << HQuat::GetMagnitude(q1) << "\n\n";
	}

	// Obrót punktu 
	{
		std::cout << "=== OBROT PUNKTU ZA POMOCA KWATERNIONU ==\n\n";

		HVector point(-1, -1, -1);
		q1 = HQuat::RotationQuaternion(1.5 * PI, HVector(1.0f, 0.0f, 0.0f));

		HVector rotated = point;
		rotated.RotateQuat(q1);

		std::cout << "Punkt " << point.ToString() << " po obroceniu o 270 stopni wokol osi x wynosi: " << rotated.ToString() << "\n\n";
	}

	// Przemiennosc mnozenia
	{
		std::cout << "=== SPRAWDZENIE PRZEMIENNOSCI MNOZENIA ==\n\n";
		q1 = HQuat(2, 1, 0, 0);
		HQuat q12 = q1 * q2;
		HQuat q21 = q2 * q1;
		std::cout << "Wynik mnozenia " << q1.ToString() << " przez" << q2.ToString() << " wynosi " << q12.ToString() << "\n";
		std::cout << "Wynik mnozenia " << q2.ToString() << " przez" << q1.ToString() << " wynosi " << q21.ToString() << "\n";
	}
	*/

	/*HLine line1 = HLine({3, 1, 5}, {-2, 4, 0});
	HLine line2 = HLine({1, -5, 3}, {-2, 4, 0});
	HLine line3 = HLine({3, -1, 2}, {-2, 2, -1});

	HPlane plane1 = HPlane(2, 3, 3, -8);
	HPlane plane2 = HPlane(2, -1 , 1, -8);
	HPlane plane3 = HPlane(4, 3, 1, 14);

	HSegment segment1 = HSegment({5, 5, 4}, {10, 10, 6});
	HSegment segment2 = HSegment({5, 5, 5}, {10, 10, 3});

	HLine line4 = HLine({3, -1, -2}, {5, 3, -4});
	HSphere sphere = HSphere({0, 0, 0}, sqrt(26));

	// ZADANIE 1
	{
		cout << "Zad 1. Punkt przeciecia prostych: " << HUtils::LineIntersect(line1, line2).ToString() <<"\n";
	}

	// ZADANIE 2
	{
		cout << "Zad 2. Kat miedzy prostymi: " << HUtils::LineAngle(line1, line2) * (180 / PI)  << " stopni\n";
	}

	// ZADANIE 3
	{
		cout << "Zad 3. Punkt przeciecia prostej i plaszczyzny: " << HUtils::LinePlaneIntersect(line3, plane1).ToString() << "\n";
	}

	// ZADANIE 4
	{
		line3 = HLine({3, -1, 2}, {-2, 2, -1});
		plane1 = HPlane(2, 3, 3, -8);
		cout << "Zad 4. Kat miedzy prosta, a plaszczyzna: " << HUtils::LinePlaneAngle(line3, plane1) * (180 / PI) << " stopni\n";
	}

	// ZADANIE 5
	{
		plane2 = HPlane(2, -1 , 1, -8);
		plane3 = HPlane(4, 3, 1, 14);
		cout << "Zad 5. Przeciecie plaszczyzn: " << HUtils::PlaneIntersect(plane2, plane3).ToString() << "\n";
	}

	// ZADANIE 6
	{
		cout << "Zad 6. Kat miedzy plaszczyznami: " << HUtils::PlaneAngle(plane2, plane3) * (180 / PI)  << " stopnie\n";
	}

	// ZADANIE 7
	{
		cout << "Zad 7. Punkt przeciecia dwoch odcinkow: " << HUtils::SegmentIntersect(segment1, segment2).ToString() << "\n";	
	}

	// ZADANIE 8
	{
		std::vector<HVector> solutions = HUtils::LineSphereIntersect(line4, sphere);
		cout << "Zad 8. Punkty przeciecia prostej i sfery: " << solutions[0].ToString() << ", " << solutions[1].ToString() << "\n";
	}*/
	
	return 0;
}
