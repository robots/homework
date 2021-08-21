#ifndef MON_hpp_
#define MON_hpp_

#include <map>

#include <net.hpp>

class Monitor {
	Network &net;

	std::map<int, int> counter;

	public:
		Monitor(Network &net);

		void run(void);

};

#endif
