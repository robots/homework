#ifndef DEV_hpp_
#define DEV_hpp_

#include <net.hpp>

class Dev {
	int id;
	Network &net;

	public:
		Dev(Network &net, int id);

		std::thread thread(void);
		void task(void);
};

#endif
