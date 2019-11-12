#ifndef ETHAN_NET_ENDIAN_
#define ETHAN_NET_ENDIAN_

#include <endian.h>
#include <byteswap.h>
#include <stdint.h>
#include <type_traits>

template<class T>
typename std::enable_if<sizeof(uint16_t) == sizeof(T), T>::type
byteswap(T val) {
    return bswap_16(val);
}

template<class T>
typename std::enable_if<sizeof(uint32_t) == sizeof(T), T>::type
byteswap(T val) {
    return bswap_32(val);
}

template<class T>
typename std::enable_if<sizeof(uint64_t) == sizeof(T), T>::type
byteswap(T val) {
    return bswap_64(val);
}

#if __BYTE_ORDER == __LITTLE_ENDIAN

/**
 *convert val to big endian
 */
template<class T>
T toBigEndian(T val) {
    return byteswap(val);    
}

/**
 *convert val to little endian
 */
template<class T>
T toLittleEndian(T val) {
    return val;
}

#else

template<class T>
T toBigEndian(T val) {
    return val;
}

template<class T>
T toLittleEndian(T val) {
    return byteswap(val);
}


#endif

#endif
