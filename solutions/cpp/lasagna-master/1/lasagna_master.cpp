#include "lasagna_master.h"
#include <algorithm>

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int time) {
    return layers.size() * time;
}

amount quantities(const std::vector<std::string>& layers) {
    int noodles = std::count(std::cbegin(layers), std::cend(layers), "noodles") * 50;
    double sauce = std::count(std::cbegin(layers), std::cend(layers), "sauce") * 0.2;
    return amount{noodles, sauce};
}

void addSecretIngredient(std::vector<std::string>& my_list, const std::vector<std::string>& friend_list) {
    my_list.back() = friend_list.back();
}
    
std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions) {
    std::vector<double> scaled_recipe = quantities;
    for (auto& q : scaled_recipe) {
        q = q * portions / 2.0;
    }
    return scaled_recipe;
}
    
void addSecretIngredient(std::vector<std::string>& my_list, std::string secret) {
    my_list.back() = secret;
}

}  // namespace lasagna_master
