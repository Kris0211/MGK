#include "HUtils.h"

#include <iostream>

#include "HLine.h"
#include "HPlane.h"
#include "HSegment.h"
#include "HSphere.h"

HVector HUtils::LineIntersect(const HLine& line1, const HLine& line2)
{
	float t = HVector::DotProduct(HVector::CrossProduct(line2.p - line1.p, line2.v), HVector::CrossProduct(line1.v, line2.v))
		/ (HVector::CrossProduct(line1.v, line2.v).Length() * HVector::CrossProduct(line1.v, line2.v).Length());
	return line1.p + line1.v * t;
}

float HUtils::LineAngle(const HLine& line1, const HLine& line2)
{
	//HVector v1normal = line1.p;
	//HVector v2normal = line2.p;

	//v1normal.Normalize();
	//v2normal.Normalize();

	return HVector::AngleBetween(line1.p, line2.p);
}

HVector HUtils::LinePlaneIntersect(const HLine& line, const HPlane& plane)
{
	float distance = HVector::DotProduct(plane.n, plane.p) * -1;
	float t = -(HVector::DotProduct(line.v, plane.n) + distance) /
		HVector::DotProduct(line.p, plane.n);
	return line.v + line.p * t;
}

float HUtils::LinePlaneAngle(const HLine& line, const HPlane& plane)
{
	//HVector lineNormal = line.v;
	//HVector planeNormal = plane.n;

	//lineNormal.Normalize();
	//planeNormal.Normalize();

	return asin(HVector::DotProduct(line.p, plane.n) / (line.p.Length() * plane.n.Length()));
}

HLine HUtils::PlaneIntersect(const HPlane& plane1, const HPlane& plane2)
{
	HLine result;
	result.v = HVector::CrossProduct(plane1.n, plane2.n);
	float length = result.v.Length();

	result.p = (HVector::CrossProduct(result.v, plane2.n) * plane1.d +
		HVector::CrossProduct(plane1.n, result.v) * plane2.d) / length;

	return result;
}

float HUtils::PlaneAngle(const HPlane& plane1, const HPlane& plane2)
{
	return HVector::AngleBetween(plane1.n, plane2.n);
}

HVector HUtils::SegmentIntersect(const HSegment& seg1, const HSegment& seg2)
{
	HVector planeNormal = HVector::CrossProduct(seg1.v, seg2.e - seg1.s);
	if(HVector::DotProduct(planeNormal, seg2.e - seg1.s) == 0)
	{
		HVector normal1 = HVector::CrossProduct(seg1.v, planeNormal);
		HVector normal2 = HVector::CrossProduct(seg2.v, planeNormal);
		if(HVector::DotProduct(seg1.s - seg2.s, normal2) * HVector::DotProduct(seg1.e - seg2.s, normal2) < 0
			&& HVector::DotProduct(seg2.s - seg1.s, normal1) * HVector::DotProduct(seg2.e - seg1.s, normal1) < 0)
		{
			return LineIntersect(HLine::StartToEnd(seg1.s, seg1.e), HLine::StartToEnd(seg2.s, seg2.e));
		}
	}
}

std::vector<HVector> HUtils::LineSphereIntersect(const HLine& line, const HSphere& sphere)
{
	HVector toLine = line.p - sphere.c;
	float a = HVector::DotProduct(line.v, line.v);
	float b = 2 * HVector::DotProduct(toLine, line.v);
	float c = HVector::DotProduct(toLine, toLine) - sphere.r * sphere.r;
	float delta = b * b - 4 * a * c;

	float t1 = (-b - sqrt(delta)) / (2 * a);
	float t2 = (-b + sqrt(delta)) / (2 * a);

	return { line.p + line.v * t1, line.p + line.v * t2 };
}
