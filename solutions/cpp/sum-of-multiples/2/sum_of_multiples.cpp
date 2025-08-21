#include "sum_of_multiples.h"

#include <numeric>
#include <set>

namespace sum_of_multiples {
    
int to(const std::vector<int>& base_values, int level) {
    std::set<int> points_set;
    for (int base_value : base_values) {
        for (int points = base_value; points < level; points += base_value) {
            points_set.insert(points);            
        }
    }
    return std::accumulate(cbegin(points_set), cend(points_set), 0);
}

}  // namespace sum_of_multiples
