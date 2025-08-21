#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>

namespace queen_attack {

class chess_board {
public:
    chess_board(const std::pair<int,int>& w, const std::pair<int,int> b);
    bool can_attack() const;
    std::pair<int, int> white() const;
    std::pair<int, int> black() const;

private:
    std::pair<int, int> w_;
    std::pair<int, int> b_;
};
    
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H