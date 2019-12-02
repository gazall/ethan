#ifndef ETHAN_BASE_NoCopyable_
#define ETHAN_BASE_NoCopyable_

namespace ethan {

class NoCopyable {
public:
    NoCopyable() = default;
    NoCopyable(const NoCopyable &) = delete;
    NoCopyable &operator=(const NoCopyable &) = delete;
};

}

#endif