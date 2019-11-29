#include "../Endian.h"
#include <arpa/inet.h>
#include <iostream>

int main() {
    int a = 5;
    int r1 = htonl(a);
    int r2 = toBigEndian(a);
    
    std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;

}
