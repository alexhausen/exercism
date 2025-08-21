#include "pangram.h"

#include <cctype>
#include <bitset>

namespace pangram {
bool is_pangram(const std::string& s) {
    std::bitset<128> bs; // bitset used for ASCII characters
    const unsigned alpha_bits = 0b11'11111111'11111111'11111111; // 26 bits representing alphabet letters
    for (const char c : s) {
        bs[c] = true;
    }
    const std::bitset<128> bs1 = bs >> static_cast<int>('a'); // lower case
    const std::bitset<128> bs2 = bs >> static_cast<int>('A'); // upper case
    bs = (bs1 | bs2);
    bs &= alpha_bits;
    return bs == alpha_bits;
}
}  // namespace pangram
