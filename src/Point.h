
#ifndef _MIN_DISK_POINT_H
#define _MIN_DISK_POINT_H

#include <vector>
#include <ostream>

namespace nomind {

using std::ostream;
using std::vector;

class Point {
private:
	double _x;
	double _y;

public:
	Point();
	Point(double x, double y);
	Point(int x, int y);
	Point(double x, int y);
	Point(int x, double y);

	double getX() const;
	double getY() const;
	bool operator <(const Point& p) const;
	bool operator ==(const Point& p) const;
};

ostream& operator <<(ostream& out, Point p);
Point getMidPoint(const Point& p1, const Point& p2);
double dist(const Point& p1, const Point& p2);
double getAngle(Point p1, Point p2, Point p3);
Point getFarthest(const Point& p, const vector<Point>& list);
Point getNearest(const Point& p, const vector<Point>& list);
void print(vector<Point> list);

}

#endif

