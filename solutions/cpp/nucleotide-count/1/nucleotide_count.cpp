#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {
std::map<char, int> count(const std::string& dna) {

    std::map<char, int> nucleotides = { {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} };
    for (char c: dna) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            throw std::invalid_argument{"invalid dna sequence"};
        }
        nucleotides[c]++;
    }
    return nucleotides;
}
}  // namespace nucleotide_count
