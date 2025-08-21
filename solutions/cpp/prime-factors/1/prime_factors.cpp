#include "prime_factors.h"

#include <vector>

namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> r;
    long long i = 2;
    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            r.push_back(i);
        } else {
            i++;
        }
    }
    return r;
}

}  // namespace prime_factors
