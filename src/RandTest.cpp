
#include <cstdlib>

#include "RandTest.h"

namespace nomind {

vector<Point>
RandTest::getPoints() {
	int count = 4;
	vector<Point> list;
	while(count--) {
		int x = rand()%100;
		int y = rand()%100;
		Point p(x, y);
		list.push_back(p);
	}
	return list;
}

Point
RandTest::getPivot() {
	int x = rand()%200 - 100;
	int y = rand()%200 - 100;
	return Point(x, y);
}

}
