#ifndef ETHAN_NET_POLL_H
#define ETHAN_NET_POLL_H

#include <map>
#include <vector>
#include <sys/epoll.h>
namespace ethan {

class Channel;
class Poller {
public:
    Poller();
    ~Poller();
    void updateChannel(const Channel &chan);
    void poll();
private:
    int epfd;
    std::vector<struct epoll_event> events;
};

}

#endif