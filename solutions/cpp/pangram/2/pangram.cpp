#include "pangram.h"

#include <cctype>
#include <bitset>

namespace pangram {
bool is_pangram(const std::string& s) {
    std::bitset<128> bs;   
    const unsigned alpha_bits = 0b11'11111111'11111111'11111111; // 26 bits
    for (char c : s) {
        bs[std::tolower(c)] = true;
    }
    bs >>= static_cast<int>('a');
    bs &= alpha_bits;
    return bs == alpha_bits;
}
}  // namespace pangram
