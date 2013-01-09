
#ifndef _MIN_DISK_RAND_TEST_H
#define _MIN_DISK_RAND_TEST_H

#include <vector>

#include "Test.h"
#include "Point.h"

namespace nomind {

using std::vector;

class RandTest : public Test {
public:
	vector<Point> getPoints();
	Point getPivot();
	void runTest();
};


}

#endif
