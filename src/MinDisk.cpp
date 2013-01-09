
#include <map>

#include "MinDisk.h"
#include "Line.h"
#include "Constants.h"

namespace nomind {

using std::map;

MinDisk::MinDisk(vector<Point> list, Point pivot) {
	_list = list;
	_pivot = pivot;
}

Point
MinDisk::solve() {
	Point p1 = getFarthest(_pivot, _list);
	Line l1(p1, _pivot);

	vector<Point> pList;
	map<Point, Point> mList;
	int n = _list.size();

	for(int i=0; i<n; i++) {
		if(_list[i] == p1) {
			continue;
		}

		Line ppd = getPerpBisector(p1, _list[i]);

		Point p = getIntersection(l1, ppd);
		mList[p] = _list[i];
		pList.push_back(p);
	}

	Point pt = getNearest(p1, pList);
	Point p2 = mList[pt];
	double minAngle  = pi/4.0 + 0.1;
	Point p3;
	for(int i=0; i<n; i++) {
		Point p = _list[i];
		if(p == p1 || p == p2) {
			continue;
		}
		double angle = getAngle(p1, p, p2);
		if(angle > pi/4.0) {
			angle = pi/4.0 - angle;
		}
		if(angle < minAngle) {
			minAngle = angle;
			p3 = p;
		}
	}

	Line a1 = getPerpBisector(p1, p2);
	Line a2 = getPerpBisector(p1, p3);
	Point circumcenter = getIntersection(a1, a2);

	// cout<<p1<<" "<<p2<<" "<<p3<<endl;
	// cout<<dist(p1, circumcenter)<<" "<<dist(p2, circumcenter)<<" "<<dist(p3, circumcenter)<<endl;

	return circumcenter;
}

}
