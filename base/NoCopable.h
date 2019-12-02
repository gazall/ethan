#ifndef ETHAN_BASE_NOCOPABLE_
#define ETHAN_BASE_NOCOPABLE_

namespace ethan {

class NoCopable {
public:
    NoCopable() = default;
    NoCopable(const NoCopable &) = delete;
    NoCopable &operator=(const NoCopable &) = delete;
};

}

#endif