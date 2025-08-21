#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {

long square_of_sum(long n) {
    long sum = 0;
    for (long i = 1; i <= n; i++) {
        sum += i;
    }
    long sq_sum = pow(sum, 2.0);
    return sq_sum;
}

long sum_of_squares(long n) {
    long sum_sq = 0;
    for (long i = 1; i <= n; i++) {
        sum_sq += pow(i, 2.0);
    }
    return sum_sq;
}

long difference(long n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
