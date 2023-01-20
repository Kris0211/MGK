#pragma once
#include <vector>

#include "HVector.h"

class HSphere;
class HSegment;
class HPlane;
class HLine;

class HUtils
{
public:
	static HVector LineIntersect(const HLine& line1, const HLine& line2);
	static float LineAngle(const HLine& line1, const HLine& line2);
	static HVector LinePlaneIntersect(const HLine& line, const HPlane& plane);
	static float LinePlaneAngle(const HLine& line, const HPlane& plane);
	static HLine PlaneIntersect(const HPlane& plane1, const HPlane& plane2);
	static float PlaneAngle(const HPlane& plane1, const HPlane& plane2);
	static HVector SegmentIntersect(const HSegment& seg1, const HSegment& seg2);
	static std::vector<HVector> LineSphereIntersect(const HLine& line, const HSphere& sphere);
	static bool IsRayIntersectAABBUnitBox(HLine line);
};
