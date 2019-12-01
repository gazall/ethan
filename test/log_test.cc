#include "base/log_wrapper.h"
#include <pthread.h>
#include <thread>

void *info(void *arg) {
    LOG_INFO << "first info";
}

void *debug(void *arg) {
    LOG_DEBUG << "first debug";
}

void info1() {
    LOG_INFO << "first info";
}

void debug1() {
    LOG_DEBUG << "first debug";
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &info, NULL);
    pthread_create(&t2, NULL, &debug, NULL);
    std::thread t3(info1);
    std::thread t4(debug1);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    t3.join();
    t4.join();
    
    return 0;
}