#include "EventLoop.h"

namespace ethan {

void EventLoop::runEventLoop() {
    while (true) {
        poller.poll();
    }
}

void EventLoop::updateChannel(const Channel &chan) {
    if (chan.getEvents() != 0) {
        channelMap[chan.getFd()] = chan;
    } else {
        channelMap.remove(chan.getFd());
    }
    poller.updateChannel(chan);
}

}