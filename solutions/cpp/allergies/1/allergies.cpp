#include "allergies.h"

namespace allergies {

static const char* allergenics[] = {
    "eggs",
    "peanuts",
    "shellfish",
    "strawberries",
    "tomatoes",
    "chocolate",
    "pollen",
    "cats"
};

allergy_test::allergy_test(unsigned score) {
    const unsigned allergenics_size = sizeof(allergenics)/sizeof(allergenics[0]);
    for (unsigned i = 0; i < allergenics_size; i++) { 
       if (score & (1 << i)) {
           allergies_.emplace(allergenics[i]);
       }
    }
};

bool allergy_test::is_allergic_to(const char* allergenic) {
    return allergies_.count(allergenic) != 0;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    return allergies_;
}

}  // namespace allergies
