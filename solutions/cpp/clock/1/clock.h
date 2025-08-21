#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {class clock;}

bool operator==(const date_independent::clock& a, const date_independent::clock& b);
bool operator!=(const date_independent::clock& a, const date_independent::clock& b);

namespace date_independent {

class clock {
public:
    static clock at(int h, int m);
    operator std::string() const;
    clock plus(int) const;

private:
    int h_;
    int m_;

friend bool ::operator==(const date_independent::clock& a, const date_independent::clock& b);
friend bool ::operator!=(const date_independent::clock& a, const date_independent::clock& b);
};

}  // namespace date_independent

#endif // CLOCK_H
