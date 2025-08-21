#include "queen_attack.h"
#include <cstdlib>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(const std::pair<int,int>& white, const std::pair<int,int>& black) : w_{white}, b_{black} {
    if (white.first < 0 || white.second < 0 || black.first < 0 || black.second < 0) {
        throw std::domain_error{"invalid value: negative"};
    }
    if (white.first >7 || white.second > 7 || black.first > 7 || black.second > 7) {
        throw std::domain_error{"invalid value: out of bounds"};
    }
    if (white.first == black.first && white.second == black.second) {
        throw std::domain_error("invalid value: same place");
    }
}

bool chess_board::can_attack() const {
    if (w_.first == b_.first || w_.second == b_.second) {
        return true;
    }
    int f = std::abs(w_.first - b_.first);
    int s = std::abs(w_.second - b_.second);
    return f == s;
}

std::pair<int, int> chess_board::white() const {
    return w_;
}
std::pair<int, int> chess_board::black() const {
    return b_;
}

}  // namespace queen_attack
