#include "collatz_conjecture.h"
#include <stdexcept>

int collatz_conjecture::steps(int n) {
    if (n <= 0) throw std::domain_error("invalid input");
    int i = 0;
    while (n != 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        i++;        
    }
    return i;
}
