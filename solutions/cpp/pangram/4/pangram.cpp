#include "pangram.h"

#include <cctype>
#include <bitset>

namespace pangram {
bool is_pangram(const std::string& s) {
    // bitset used for ASCII characters
    std::bitset<128> bs;
    for (const char c : s) {
        bs[c] = true;
    }
    // 26 bits representing alphabet letters
    const unsigned alphabet = 0b11'11111111'11111111'11111111;
    // lower case letters
    std::bitset<128> bs1 = bs >> static_cast<int>('a');
    bs1 &= alphabet;
    const unsigned lc = bs1.to_ulong();
    // upper case letters
    std::bitset<128> bs2 = bs >> static_cast<int>('A');
    bs2 &= alphabet;
    const unsigned uc = bs2.to_ulong();
    // verify if all letters were used
    return (lc | uc) == alphabet;
}
}  // namespace pangram
