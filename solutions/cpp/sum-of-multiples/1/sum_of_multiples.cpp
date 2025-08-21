#include "sum_of_multiples.h"

#include <numeric>
#include <set>

namespace sum_of_multiples {
    
int to(std::vector<int> base_values, int level) {
    std::set<int> points_set;
    for (int base_value : base_values) {
        int i = 1;
        int points = base_value * i;
        while (points < level) {
            points_set.insert(points);
            points = base_value * i;
            i++;
        }
    }
    return std::accumulate(cbegin(points_set), cend(points_set), 0);
}

}  // namespace sum_of_multiples
