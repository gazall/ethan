#ifndef ETHAN_BASE_LOG_WRAPPER_
#define ETHAN_BASE_LOG_WRAPPER_

#include "base/log/easylogging++.h"

namespace ethan {

class Log_Wrapper {
public:
    Log_Wrapper();
};

#define LOG_DEBUG LOG(DEBUG)
#define LOG_INFO LOG(INFO)
#define LOG_WARN LOG(WARN)
#define LOG_ERROR LOG(ERROR)
}

#endif