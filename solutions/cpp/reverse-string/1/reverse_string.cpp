#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const std::string& input) {
        std::string reversed;
        reversed.reserve(input.size());
        for (auto it = input.rbegin(); it != input.rend(); ++it) {
            reversed += *it;
        }
        return reversed;
    }
}  // namespace reverse_string
