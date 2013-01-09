
#ifndef _MIN_DISK_TOY_TEST_H
#define _MIN_DISK_TOY_TEST_H

#include <vector>

#include "Test.h"
#include "Point.h"

namespace nomind {

using std::vector;

class ToyTest : public Test {
public:
	vector<Point> getPoints();
	Point getPivot();
	void runTest();
};


}

#endif
