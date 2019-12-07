#include "IOManager.h"
#include "base/Exception.h"
#include "base/log_wrapper.h"
#include <sys/epoll.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

namespace ethan {

IOManager::IOManager() {
    epfd = ::epoll_create1(0);
    if (epfd < 0) {
        throw Exception(strerror(errno));
    }
}

IOManager::~IOManager() {
    ::close(epfd);
}

bool IOManager::addEvent(Socket::ptr sockptr, Event_Cb cb, int type) {
    if (sockptr == nullptr || cb == nullptr) {
        LOG_ERROR << "IOManager::addEvent, sockptr or cb is null.";
        return false;
    }

    if (type != EVENT_READ && type != EVENT_WRITE) {
        LOG_ERROR << "IOManager::addEvent, type : " << type;
        return false;
    }

    auto it = socketCtxs.find(sockptr->getFd());
    if (it != socketCtxs.end()) {
        it->second.addEvent(cb, type);
        return true;
    }

    SocketCtx ctx(sockptr);
    ctx.addEvent(cb, type);
    socketCtxs.insert(std::pair<int, SocketCtx>(sockptr->getFd(), std::move(ctx)));
    return true;
}

bool IOManager::delEvent(Socket::ptr sockptr, int type) {

}

void IOManager::run() {

}

}