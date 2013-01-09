
#ifndef _MIN_DISK_DOUBLE_H
#define _MIN_DISK_DOUBLE_H

#include <ostream>

namespace nomind {

using std::ostream;

class Double {
private:
	double _val;

public:
	Double(double d);
	bool operator <(const Double d) const;
	bool operator ==(const Double d) const;
	Double& operator =(double d);

	friend ostream& operator <<(ostream& out, Double d);
};

}

#endif
