
#include <stdexcept>

#include "Line.h"
#include "Constants.h"
#include "Point.h"

namespace nomind {

using std::runtime_error;

Line::Line(const Point& p1, const Point& p2) {
	double x1 = p1.getX(), x2 = p2.getX();
	double y1 = p1.getY(), y2 = p2.getY();

	_A = y1 - y2;
	_B = x2 - x1;
	_C = x1*y2 - x2*y1;
}

Line::Line(const Point& p, double slope) {
	double x = p.getX();
	double y = p.getY();

	if(slope == infinity) {
		_A = 1.0;
		_B = 0.0;
		_C = -1.0*x;
	} else {
		double c = y - slope * x;

		_A = slope;
		_B = -1.0;
		_C = c;
	}
}

double Line::getSlope() const {
	return (-1.0*_A) / _B;
}

Point getIntersection(const Line& l1, const Line& l2) {
	double A1 = l1._A, B1 = l1._B, C1 = l1._C;
	double A2 = l2._A, B2 = l2._B, C2 = l2._C;

	double d = (A1*B2 - A2*B1);
	if(d == 0.0) {
		throw runtime_error("no intersection for parallel lines");
	}

	double x = (C2*B1 - C1*B2) / d;
	double y = (C2*A1 - C1*A2) / (-1.0*d);
	return Point(x, y);

}

double getSlope(const Point& p1, const Point& p2) {
	double x1 = p1.getX(), x2 = p2.getX();
	double y1 = p1.getY(), y2 = p2.getY();
	if(abs(x2 - x1) < epsilon) {
		return infinity;
	}
	return (y2 - y1)/(x2 - x1);
}

Line getPerpBisector(const Point& p1, const Point& p2) {
	Point m = getMidPoint(p1, p2);
	double t = getSlope(p1, p2), s;
	if(t == infinity) {
		s = 0.0;
	} else if(abs(t) <epsilon) {
		s = infinity;
	} else {
		s = -1.0/t;
	}
	Line l(m, s);
	return l;
}

}
