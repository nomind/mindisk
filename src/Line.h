
#ifndef _MIN_DISK_LINE_H
#define _MIN_DISK_LINE_H

#include "Point.h"

namespace nomind {

class Line {

private:
	double _A;
	double _B;
	double _C;

public:
	Line(const Point& p1, const Point& p2);
	Line(const Point& p, double slope);
	double getSlope() const;

	friend Point getIntersection(const Line& l1, const Line& l2);
};

Point getIntersection(const Line& l1, const Line& l2);
Line getPerpBisector(const Point& p1, const Point& p2);

}

#endif
