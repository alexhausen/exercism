#include "rna_transcription.h"

#include <algorithm>

static char map[] = {
'U', // A
' ', // B
'G', // C
' ', // D
' ', // E
' ', // F
'C', // G
' ', // H
' ', // I
' ', // J
' ', // K
' ', // L
' ', // M
' ', // N
' ', // O
' ', // P
' ', // Q
' ', // R
' ', // S
'A', // T
};

namespace rna_transcription {
char to_rna(char c) {
    return map[static_cast<int>(c) - 'A'];
}

std::string to_rna(const std::string& dna) {
    std::string rna{dna};
    for (unsigned i = 0; i < dna.length(); i++) {
        rna[i] = to_rna(dna[i]);
    }
    return rna;
}
}  // namespace rna_transcription
