#include "log_wrapper.h"
INITIALIZE_EASYLOGGINGPP

namespace ethan {
    
    Log_Wrapper::Log_Wrapper() {
        el::Configurations fileConf("/opt/ethan/log_config.conf");
        el::Loggers::reconfigureAllLoggers(fileConf);
    }

    static Log_Wrapper log_wrapper;
}
