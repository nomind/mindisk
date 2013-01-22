
#include <cstdlib>
#include <cmath>

#include "ConvexPolygonTest.h"
#include "RandGen.h"
#include "Constants.h"

namespace nomind {

vector<Point>
ConvexPolygonTest::getPoints(int count) {
	vector<Point> list;
	double angle = 0, inc = (2*pi) / count;
	double x = 0.0, y = 0.0;
	double max_d = 1000.0;
	while(count--) {
		list.push_back(Point(x, y));
		double d = RandGen::getRandInt() /  max_d;
		x += d*cos(angle);
		y += d*sin(angle);
		angle += inc;
	}
	return list;
}

Point
ConvexPolygonTest::getPivot() {
	return getRandomPoint();
}

Point
ConvexPolygonTest::getRandomPoint() {
	int l1 = max_abs_coordinate_limit;
	int l2 = l1 * 2;
	int x = RandGen::getRandInt()%l2 - l1;
	int y = RandGen::getRandInt()%l2 - l1;
	return Point(x, y);
}

}
