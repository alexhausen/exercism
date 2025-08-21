#include "grains.h"

namespace grains {
    long long unsigned square(unsigned n) {
        long long unsigned x = 1u;
        for (unsigned i = 1u; i < n; i++) {
            x *= 2;
        }
        return x; // 2^(n-1)
    }

    long long unsigned total() {
        long long unsigned x = 0llu;
        for (unsigned i = 1; i <= 64u; i++) {
            x += square(i);
        }
        return x;
    }
}  // namespace grains
