
#include <iostream>
#include <chrono>
#include <thread>

#include <mon.hpp>

using namespace std::chrono_literals;

Monitor::Monitor(Network &net) : net(net)
{
}

void Monitor::run(void)
{
	while (this->net.is_up()) {
		int id;
		float measurement; // not used in this example

		int read = this->net.recv(id, measurement);
		if (read == 1) {
			this->counter[id] ++;
		} else {
			// sleep and wait for packet to come
			std::this_thread::sleep_for(1ms);
		}
	}

	for (auto const& [dev, cnt] : this->counter) {
		std::cout << "Device " << dev << " count: " << cnt << std::endl;
	}
}
