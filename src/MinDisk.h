
#ifndef _MIN_DISK_MIN_DISK_H
#define _MIN_DISK_MIN_DISK_H

#include <vector>

#include "Point.h"

namespace nomind {

using std::vector;

class MinDisk {
	vector<Point> _list;
	Point _pivot;
public:
	MinDisk(vector<Point> list, Point pivot);
	Point solve();
};

}

#endif
