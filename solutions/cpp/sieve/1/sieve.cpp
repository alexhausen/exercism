#include "sieve.h"

namespace sieve {

std::vector<int> primes(int n) {
    std::vector<int> p;
    std::vector<bool> l;
    for (int x = 0; x <= n; x++) {
        l.push_back(false);
    }
    for (unsigned i = 2; i < l.size(); i++) {
        if (l[i] == false) {
            p.push_back(i);
            int j = 2;
            int not_prime = i * j;
            while (not_prime <= n) {
                l[not_prime] = true;
                j++;
                not_prime = i * j;
            }
        }
    }
    return p;
}

}  // namespace sieve
