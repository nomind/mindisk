
#include <iostream>
#include <stdexcept>
#include <cmath>

#include "Point.h"
#include "Constants.h"

namespace nomind {

using std::vector;
using std::runtime_error;
using std::ostream;
using std::cout;
using std::endl;

Point::Point() {
	_x = 0.0;
	_y = 0.0;
}

Point::Point(double x, double y) {
	_x = x;
	_y = y;
}

Point::Point(int x, int y) {
	_x = (double)x;
	_y = (double)y;
}

Point::Point(int x, double y) {
	_x = (double)x;
	_y = y;
}

Point::Point(double x, int y) {
	_x = x;
	_y = (double)y;
}

double
Point::getX() const {
	return _x;
}

double
Point::getY() const {
	return _y;
}

bool
Point::operator <(const Point& p) const {
	if(_x == p._x) {
		return _y < p._y;
	}
	return _x < p._x;
}

bool
Point::operator ==(const Point& p) const {
	if(abs(_x - p._x) < epsilon && (_y - p._y) < epsilon) {
		return true;
	}
	return false;
}

ostream& operator <<(ostream& out, Point p) {
	out<<"("<<p.getX()<<", "<<p.getY()<<")";
	return out;
}

Point getMidPoint(const Point& p1, const Point& p2) {
	double x = (p1.getX() + p2.getX()) / 2.0;
	double y = (p1.getY() + p2.getY()) / 2.0;
	Point p(x, y);
	return p;
}

double dist(const Point& p1, const Point& p2) {
	double x1 = p1.getX(), x2 = p2.getX();
	double y1 = p1.getY(), y2 = p2.getY();
	double dx = x1 - x2, dy = y1 - y2;

	return sqrt(dx * dx + dy * dy);
}

double getAngle(Point p1, Point p2, Point p3) {
	double p12 = dist(p1, p2);
	double p23 = dist(p2, p3);
	double p31 = dist(p3, p1);

	double angle = (p12 * p12 + p23 * p23 - p31 * p31) / (2.0 * p12 * p23);
	return angle;
}

Point getFarthest(const Point& p, const vector<Point>& list) {
	int n = list.size();
	if(n == 0) {
		throw runtime_error("null list of points");
	}

	if(n == 1) {
		return list[0];
	}

	double maxDist = 0.0;
	Point ans(p);

	for(int i=0; i<n; i++) {
		double d = dist(p, list[i]);
		if(d > maxDist) {
			maxDist = d;
			ans = list[i];
		}
	}
	return ans;
}

Point getNearest(const Point& p, const vector<Point>& list) {
	int n = list.size();
	if(n == 0) {
		throw runtime_error("null list of points");
	}

	if(n == 1) {
		return list[0];
	}

	double maxDist = dist(p, list[0]);
	Point ans(list[0]);

	for(int i=0; i<n; i++) {
		double d = dist(p, list[i]);
		if(d > maxDist) {
			maxDist = d;
			ans = list[i];
		}
	}
	return ans;
}

void print(vector<Point> list) {
	int n = list.size();
	for(int i=0; i<n-1; i++) {
		cout<<list[i]<<", ";
	}
	cout<<list[n-1]<<endl;
}

}
