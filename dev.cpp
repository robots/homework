#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>

#include <dev.hpp>

using namespace std::chrono_literals;

Dev::Dev(Network &net, int id) : net(net), id(id)
{
}

std::thread Dev::thread(void)
{
	return std::thread([=] { task(); });
}

void Dev::task(void)
{
	while (this->net.is_up()) {
		// make fake measurement and send it to monitor
		float m = std::rand() / RAND_MAX;
		net.send(id, m);
	
		// sleep for random time 100-1000ms
		//std::mt19937_64 eng{std::random_device{}()};
		//std::uniform_int_distribution<> dist{100, 1000};
		//std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});

		std::this_thread::sleep_for(100ms);
	}
}
