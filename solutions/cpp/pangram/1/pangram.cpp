#include "pangram.h"

#include <algorithm>
#include <array>
#include <cctype>
	
namespace pangram {
bool is_pangram(const std::string& s) {
    std::array<bool, 26> v = {false};
    for (char c : s) {
        if (std::isalpha(c)) {
            int i = std::tolower(c) - static_cast<int>('a');
            v[i] = true;
        }
    }
    return std::all_of(cbegin(v), cend(v), [](bool x){ return x; });
}
}  // namespace pangram
