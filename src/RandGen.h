
#ifndef _MIN_DISK_RAND_GEN_H
#define _MIN_DISK_RAND_GEN_H

namespace nomind {

class RandGen {
private:
	static RandGen _randGen;

	RandGen();

public:
	const static int MAX_INT_LIMIT;
	const static double MAX_DOUBLE_LIMIT;

	static int getRandInt();
	static double getRandDouble();
};

}

#endif
