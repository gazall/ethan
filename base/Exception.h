#ifndef ETHAN_BASE_EXCEPTION
#define ETHAN_BASE_EXCEPTION

#include <string>
#include <exception>

class Exception : public std::exception {
public:
    Exception(const std::string &w) {
        msg = w;
    }
    const char *what() const noexcept override {
        return msg.c_str();
    }
private:
    std::string msg;
};

#endif