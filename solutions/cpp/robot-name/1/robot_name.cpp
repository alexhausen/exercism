#include "robot_name.h"

#include <ctime>
#include <cstdlib>
#include <unordered_set>

namespace robot_name {

std::unordered_set<std::string> names_;

// random [0, n[
int random(int n) {
    return rand() % n;
}

char random_letter() {
    return random(26) + 'A';
}

char random_digit() {
    return random(10) + '0';
}
    
robot::robot() {
    reset();
}

std::string robot::name() const {
    return name_;
}

void robot::reset() {
    std::string new_name;
   // srand(time(nullptr));
    do {
        char str[6];
        str[0] = random_letter();
        str[1] = random_letter();
        str[2] = random_digit();
        str[3] = random_digit();
        str[4] = random_digit();
        str[5] = '\0';
        new_name = std::string{str};
    } while (names_.count(new_name) != 0);
    names_.insert(new_name);
    name_ = new_name;
}

}  // namespace robot_name
