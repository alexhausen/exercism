#include "triangle.h"
#include <stdexcept>

namespace triangle {
    
flavor kind(float a, float b, float c) {
    bool illegal = a == 0 || b == 0 || b == 0;
    if (illegal) {
        throw std::domain_error{"illegal triangle"};
    }
    bool is_triangle = 
        a + b >= c &&
        b + c >= a &&
        a + c >= b;
    if (!is_triangle) {
        throw std::domain_error{"not triangle"};
    }
    if (a == b && b == c) {
        return flavor::equilateral;
    }
    if (a != b && b != c && a != c) {
        return flavor::scalene;
    }
    return flavor::isosceles;
}

}  // namespace triangle
