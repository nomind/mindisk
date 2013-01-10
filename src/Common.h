
#ifndef _MIN_DISK_COMMON_H
#define _MIN_DISK_COMMON_H

#include <iostream>

namespace nomind {

using std::ostream;
using std::cout;
using std::endl;

class DebugLog : public ostream {

};

template<class T>
DebugLog&
operator <<(DebugLog& debug_logger, const T& out) {
	if(debug_log) {
		cout<<out;
	}
	return debug_logger;
}

static DebugLog debug;

}

#endif
