
#include "Constants.h"
#include "Double.h"

namespace nomind {

Double::Double(double d) {
	_val = d;
}

Double&
Double::operator =(double d) {
	_val = d;
	return *this;
}

bool
Double::operator <(const Double d) const {
	return d._val - _val > epsilon;
}

bool
Double::operator ==(const Double d) const {
	return abs(d._val - _val) < epsilon;
}

ostream& operator <<(ostream& out, Double d) {
	out<<d._val;
	return out;
}

}
