
#ifndef _MIN_DISK_CONVEX_POLYGON_TEST_H
#define _MIN_DISK_CONVEX_POLYGON_TEST_H

#include <vector>

#include "Test.h"
#include "Point.h"

namespace nomind {

using std::vector;

class ConvexPolygonTest : public Test {
public:
	vector<Point> getPoints(int count);
	Point getPivot();
	Point getRandomPoint();
};


}

#endif
