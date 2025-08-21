#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {

std::string encode(const std::string& s) {
    std::string r;
    r.reserve(s.size());
    unsigned j = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        char c = s[i];
        if (!std::isdigit(c) && !std::isalpha(c)) {
            continue;
        }
        if (j > 0 && j % 5 == 0 && j != s.size() - 1) {
            r.push_back(' ');
        }
        j++;
        if (std::isalpha(c)) {
            c = 'z' - std::tolower(c) + 'a';
        }
        r.push_back(c); 
    }
    return r;
}

std::string decode(const std::string& s) {
    std::string r;
    r.reserve(s.size());
    for (char c: s) {
        if (c == ' ') {
            continue;
        }
        if (std::isalpha(c)) {
            c = 'z' - c + 'a';
        }
        r.push_back(c);
    }
    return r;
}
    
}  // namespace atbash_cipher
