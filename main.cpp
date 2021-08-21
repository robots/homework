#include <iostream>
#include <thread>
#include <vector>

#include <net.hpp>
#include <mon.hpp>
#include <dev.hpp>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
	const int number_of_devices = 3;

	std::vector<Dev *> devs;
	std::vector<std::thread> threads;

	Network net;

	// create and start devices
	for(int i = 0; i < number_of_devices; i++) {
		Dev *d = new Dev(net, i);
		devs.push_back(d);
		threads.push_back(d->thread());
	}

	// create monitor and start thread
	Monitor mon(net);
	threads.emplace_back(&Monitor::run, mon);

	// let system run for some time
	std::this_thread::sleep_for(2s);

	// down the net, signal all threads to finish
	net.down();

	// join all threads
	for (auto &t : threads) {
		t.join();
	}

	// clean up
	for (auto d : devs) {
		delete d;
	}

	return 0;
}
