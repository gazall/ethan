#ifndef ETHAN_NET_IOMANAGER_H
#define ETHAN_NET_IOMANAGER_H

#include "Socket.h"
#include "SocketCtx.h"
#include <map>

namespace ethan {

/**           IOManager
*                ^
*                | 
*             SocketCtx
*/

class IOManager {
public:
    typedef std::shared_ptr<IOManager> ptr;
    IOManager();
    ~IOManager();
    bool addEvent(Socket::ptr sockptr, Event_Cb cb, int type);
    
    //seems not a good way to del event from IOManager, maybe 
    //we shuold give the power to SockCtx to add/del event.
    bool delEvent(Socket::ptr sockptr, int type);
    void run();
private:
    int epfd = -1;
    std::map<int, SocketCtx> socketCtxs;
};

}
#endif