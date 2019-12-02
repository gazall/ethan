#include <base/NoCopable.h>

using namespace ethan;

class Copable : public NoCopable {

};

int main() {
    Copable src;
    Copable copy(src);  //compile should be failed.
}