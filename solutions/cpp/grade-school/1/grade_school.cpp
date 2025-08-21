#include "grade_school.h"

#include <algorithm>

namespace grade_school {
void school::add(const std::string& name, int g) {
    auto it = std::lower_bound(roster_[g].begin(), roster_[g].end(), name);
    roster_[g].insert(it, name);
}
    
std::map<int, std::vector<std::string>> school::roster() const {
    return roster_;
}

std::vector<std::string> school::grade(int g) const {
    auto it = roster_.find(g);
    if (it != roster_.end()) return it->second;
    return {};
}

}  // namespace grade_school
