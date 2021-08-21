#ifndef NET_hpp_
#define NET_hpp_

#include <queue>
#include <mutex>
#include <utility>


typedef std::pair<int, float> packet_t;

class Network
{
	bool up;
	std::queue<packet_t> q;
	std::mutex q_mtx;

	public:
		Network();

		void down();
		bool is_up();

		int send(const int id, const float measurement);
		int recv(int &id, float &measurement);
};


#endif
