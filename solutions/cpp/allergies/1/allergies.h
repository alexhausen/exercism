#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <unordered_set>
#include <string>

namespace allergies {

class allergy_test{
public:
    allergy_test(unsigned score);
    bool is_allergic_to(const char* allergenic);
    std::unordered_set<std::string> get_allergies() const;
private:
    std::unordered_set<std::string> allergies_;
};
    
}  // namespace allergies

#endif // ALLERGIES_H