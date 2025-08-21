#pragma once

#include <string>

namespace star_map {
enum class System { BetaHydri, EpsilonEridani, Sol, AlphaCentauri, DeltaEridani, Omicron2Eridani };
}

namespace heaven {

class Vessel {
    public:
    Vessel(std::string n, int gen) : name{n}, generation{gen}, current_system{star_map::System::Sol}, busters{0} {}
    Vessel(std::string n, int gen, star_map::System system) : name{n}, generation{gen}, current_system{system}, busters{0} {}

    Vessel replicate(std::string new_name) const {
        return Vessel{new_name, generation + 1, current_system};
    }

    void make_buster() {
        busters++;
    }

    bool shoot_buster() {
        if (busters > 0) {
            busters--;
            return true;
        }
        return false;
    }

    std::string name;
    int generation;
    star_map::System current_system;
    int busters;
};

std::string get_older_bob(const Vessel& v1, const Vessel& v2);

bool in_the_same_system(const Vessel& v1, const Vessel& v2);

}
