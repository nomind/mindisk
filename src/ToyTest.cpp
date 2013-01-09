
#include "ToyTest.h"

namespace nomind {

vector<Point>
ToyTest::getPoints() {
	vector<Point> list;
	Point A(-12, 1);
	Point B(-6, 2);
	Point C(1, 3);
	Point D(4, 6);
	Point E(10, -1);
	Point F(5, -2);
	Point G(2, -7);
	Point H(-7, -4);

	list.push_back(A);
	list.push_back(B);
	list.push_back(C);
	list.push_back(D);
	list.push_back(E);
	list.push_back(F);
	list.push_back(G);
	list.push_back(H);
	return list;
}

Point
ToyTest::getPivot() {
	//double x = 2;
	//double y = 1.8;
	int x = rand()%200 - 100;
	int y = rand()%200 - 100;
	return Point(x, y);
}

}
