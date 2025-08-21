#include "clock.h"

#include <cstdio>

namespace date_independent {

clock clock::at(int h, int m) {
    clock c;
    if (h > 0) {
        while (h >= 24) {
            h -= 24;
        }
    } else {
        while (h < 0) {
            h += 24;
        }
    }

    if (m > 0) {
        while (m >= 60) {
            m -= 60;
            h++;
        }
        while (h >= 24) {
            h -= 24;
        }
    } else {
        while (m < 0) {
            m += 60;
            h--;
        }
        while (h < 0) {
            h += 24;
        }
    }

    c.h_ = h;
    c.m_ = m;
    return c;
}

clock::operator std::string() const {
    char str[10];
    sprintf(str, "%02d:%02d", h_, m_);
    return std::string(str);
}

clock clock::plus(int m) const {
    return at(h_, m_ + m);
}

}  // namespace date_independent

bool operator==(const date_independent::clock& a, const date_independent::clock& b) {
    return a.h_ == b.h_ && a.m_ == b.m_;
}

bool operator!=(const date_independent::clock& a, const date_independent::clock& b) {
    return !(a == b);
}
