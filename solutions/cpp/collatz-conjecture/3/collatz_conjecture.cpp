#include "collatz_conjecture.h"
#include <stdexcept>

int collatz_conjecture::steps(int n) {
    if (n <= 0) throw std::domain_error("invalid input");
    int i = 0;
    for (; n != 1; i++) n = n & 1 ? 3 * n + 1 : n / 2;
    return i;
}
