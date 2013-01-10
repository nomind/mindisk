
#include <ctime>
#include <cstdlib>

#include "RandGen.h"

namespace nomind {

RandGen RandGen::_randGen;

const int RandGen::MAX_INT_LIMIT = 1000000;
const double RandGen::MAX_DOUBLE_LIMIT = 1000000.0;

RandGen::RandGen() {
	srand(time(NULL));
}

int
RandGen::getRandInt() {
	return rand() % MAX_INT_LIMIT;
}

double
RandGen::getRandDouble() {
	double t = (double)(rand() % MAX_INT_LIMIT) / MAX_INT_LIMIT;
	return t * MAX_DOUBLE_LIMIT;
}

}
