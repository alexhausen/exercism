#include "protein_translation.h"

#include <map>

namespace protein_translation {

std::vector<std::string> proteins(const std::string& rna_sequence) {
    const static std::map<std::string, std::string> rna_map = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"},
    };
    std::vector<std::string> polypeptide;
    int i = 0;
    std::string codon;
    for (char c: rna_sequence) {
        codon += c;
        i++;
        if (i % 3 != 0) continue;

        const auto it = rna_map.find(codon);
        if (it != rna_map.end()) {
            if (it->second == "STOP") {
                break;
            }
            polypeptide.push_back(it->second);
        }
        codon = "";
    }
    return polypeptide;
}

}  // namespace protein_translation
