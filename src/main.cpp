
#include <vector>
#include <map>

#include "Point.h"
#include "Double.h"
#include "MinDisk.h"
#include "RandTest.h"
#include "ToyTest.h"

using std::vector;
using std::map;

using nomind::Point;
using nomind::print;
using nomind::Double;
using nomind::MinDisk;
using nomind::dist;
using nomind::RandTest;
using nomind::ToyTest;

typedef map<Double, vector<Point> > mpp;

int
main() {
	RandTest test;
	int count = 10000;
	vector<Point> list = test.getPoints();
	print(list);

	mpp ani;

	while(count--) {
		Point p = test.getPivot();
		MinDisk minDisk(list, p);
		Point cc = minDisk.solve();
		Double r = dist(cc, list[0]);
		//cout<<cc<<endl;
		//ani[rd].push_back(p);
		ani[r].push_back(p);

	}

	int c = 0;
	for(mpp::iterator i = ani.begin(); i!=ani.end(); i++) {
		//cout<<i->first<<endl;
		//print(i->second);
		c++;
	}
	//cout<<c<<endl;

	return 0;
}

