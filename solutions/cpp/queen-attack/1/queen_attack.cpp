#include "queen_attack.h"
#include <cstdlib>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(const std::pair<int,int>& q1, const std::pair<int,int> q2) : w_{q1}, b_{q2} {
    if (q1.first < 0 || q1.second < 0 || q2.first < 0 || q2.second < 0) {
        throw std::domain_error{"invalid value: negative"};
    }
    if (q1.first >7 || q1.second > 7 || q2.first > 7 || q2.second > 7) {
        throw std::domain_error{"invalid value: out of bounds"};
    }
    if (q1.first == q2.first && q1.second == q2.second) {
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
