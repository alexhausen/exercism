#include "rna_transcription.h"
static char map[] = {'U', ' ', 'G', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A'};
char rna_transcription::to_rna(char c) { return map[static_cast<int>(c) - 'A']; }
std::string rna_transcription::to_rna(std::string dna) {
    for (unsigned i = 0; i < dna.length(); i++) dna[i] = to_rna(dna[i]);
    return dna;
}