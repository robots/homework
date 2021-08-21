
#include <net.hpp>


Network::Network() : up(true) {
}

void Network::down(void)
{
	this->up = false;
}

bool Network::is_up(void)
{
	return this->up;
}

int Network::send(const int id, const float measurement)
{
	std::lock_guard<std::mutex> guard(this->q_mtx);

	this->q.push(packet_t(id, measurement));

	return 1;
}

int Network::recv(int &id, float &measurement)
{
	std::lock_guard<std::mutex> guard(this->q_mtx);

	if (this->q.empty()) {
		return 0;
	}

	packet_t pkt = this->q.front();
	this->q.pop();

	id = pkt.first;
	measurement = pkt.second;

	return 1;
}
