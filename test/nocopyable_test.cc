#include <base/NoCopyable.h>

using namespace ethan;

class Copable : public NoCopyable {

};

int main() {
    Copable src;
    Copable copy(src);  //compile should be failed.
}