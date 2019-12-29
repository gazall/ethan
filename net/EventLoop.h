#ifndef ETHAN_NET_EVENTLOOP_H
#define ETHAN_NET_EVENTLOOP_H

#include "Poller.h"

namespace ethan {

class Channel;
class EventLoop {
public:
    using Fd = int;
    void runEventLoop();
    void updateChannel(const Channel &chan);
private:
    Poller poller;
    std::map<Fd, Channel> channelMap;
};

}

#endif