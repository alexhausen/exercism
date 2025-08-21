#if !defined(GRAINS_H)
#define GRAINS_H

namespace grains {
    constexpr long long unsigned square(unsigned n) {
        return 1llu << (n - 1); // 2^(n-1)
    }

    constexpr long long unsigned total() {
        long long unsigned x = 0llu;
        for (unsigned i = 1; i <= 64u; i++) {
            x += square(i);
        }
        return x;
    }

}  // namespace grains

#endif // GRAINS_H