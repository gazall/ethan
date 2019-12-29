#include <errno.h>
#include <unistd.h>
#include "Poller.h"
#include "Channel.h"
#include "base/log_wrapper.h"


namespace ethan {

Poller::Poller() {
    epfd = ::epoll_create1(EPOLL_CLOEXEC);
    if (epfd < 0) {
        LOG_ERROR << strerror(errno);
    }
}

Poller::~Poller() {
    ::close(epfd);
}

void Poller::updateChannel(const Channel &chan) {

}

void Poller::poll() {
    if (epfd < 0) {
        LOG_ERROR << "epfd invalid.";
        return ;
    }
}

}