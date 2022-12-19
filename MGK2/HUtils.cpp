#include "HUtils.h"

#include "HLine.h"
#include "HPlane.h"
#include "HSegment.h"

HVector HUtils::LineIntersect(const HLine& line1, const HLine& line2)
{
	float t = HVector::DotProduct(HVector::CrossProduct(line2.p - line1.p, line2.v), HVector::CrossProduct(line1.v, line2.v))
		/ (HVector::CrossProduct(line1.v, line2.v).Length() * HVector::CrossProduct(line1.v, line2.v).Length());
	return line1.p + line1.v * t;
}

float HUtils::LineAngle(const HLine& line1, const HLine& line2)
{
	return acos(HVector::DotProduct(line1.v, line2.v));
}

HVector HUtils::LinePlaneIntersect(const HLine& line, const HPlane& plane)
{
	float t = HVector::DotProduct(plane.n * -1, line.p - plane.d)
		/ HVector::DotProduct(plane.n, line.v);
	return line.p + line.v * t;
}

float HUtils::LinePlaneAngle(const HLine& line, const HPlane& plane)
{
	return acos(HVector::DotProduct(line.v, plane.n));
}

HLine HUtils::PlaneIntersect(const HPlane& plane1, const HPlane& plane2)
{
	HVector vec = HVector::CrossProduct(plane1.n, plane2.n);

	return HLine(); //TODO
}

float HUtils::PlaneAngle(const HPlane& plane1, const HPlane& plane2)
{
	return acos(HVector::DotProduct(plane1.n, plane2.n) * 0.5);
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
			return LineIntersect(HLine(seg1.s, seg1.e), HLine(seg2.s, seg2.e));
		}
	}
}

HVector HUtils::LineSphereIntersect(const HLine& line, const HSphere& sphere)
{

}
