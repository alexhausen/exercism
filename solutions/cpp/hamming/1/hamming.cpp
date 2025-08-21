#include "hamming.h"

#include <stdexcept>

namespace hamming {
int compute(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        throw std::domain_error("lenght mismatch");
    }
    int sum = 0;
    const unsigned n = str1.length();
    for (unsigned i = 0; i < n; i++) {
        sum += str1[i] != str2[i];
    }
    return sum;
}
}  // namespace hamming
