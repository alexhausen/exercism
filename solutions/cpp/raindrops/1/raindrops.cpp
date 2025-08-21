#include "raindrops.h"

namespace raindrops {
std::string convert(int n) {
    std::string r;
    if (n % 3 == 0) {
        r += "Pling";
    }
    if (n % 5 == 0) {
        r += "Plang";
    }
    if (n % 7 == 0) {
        r += "Plong";
    }
    if (r.empty()) {
        r = std::to_string(n);
    }
    return r;
}
}  // namespace raindrops
