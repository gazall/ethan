#ifndef ETHAN_NET_CHANNEL_H
#define ETHAN_NET_CHANNEL_H

#include <sys/epoll.h>

namespace {
    uint32_t NONE_EVENT = 0;
    uint32_t READ_EVENT = EPOLLIN | EPOLLPRI;
    uint32_t WRITE_EVENT = EPOLLOUT;
}

namespace ethan {

class EventLoop;
class Channel {
public:
    typedef std::function<void ()> EventCallback; 
    
    Channel(EventLoop *l, int f) : 
        loop(l), fd(f), events(NONE_EVENT) {

    }
    void setReadCallback(EventCallback cb) {
        readcb = std::move(cb);
    }
    void setWriteCallback(EventCallback cb) {
        writecb = std::move(cb);
    }
    void setCloseCallback(EventCallback cb) {
        closecb = std::move(cb);
    }
    void setErrorCallback(EventCallback cb) {
        errorcb = std::move(cb);
    }
    void enableRead() {
        events |= READ_EVENT;
    }
    void enableWrite() {
        events |= WRITE_EVENT;
    }
    void update() {
        loop->updateChannel(*this);
    }
    uint32_t getEvents() {
        return events;
    }
    int getFd() {
        return fd;
    }
private:
    EventCallback readcb;
    EventCallback writecb;
    EventCallback errorcb;
    EventCallback closecb;
private:
    EventLoop *loop;
    int fd;
    uint32_t events;
};

}

#endif