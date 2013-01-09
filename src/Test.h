
#ifndef _MIN_DISK_TEST_H
#define _MIN_DISK_TEST_H

#include <vector>

#include "Point.h"

namespace nomind {

using std::vector;

class Test {
public:
	virtual ~Test();

	virtual vector<Point> getPoints() = 0;
	virtual Point getPivot() = 0;
};

}

#endif
