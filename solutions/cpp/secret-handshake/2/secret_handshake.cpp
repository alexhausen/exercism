#include "secret_handshake.h"

#include <algorithm>

static const char* actions[] = {
    /* 00001 */ "wink",
    /* 00010 */ "double blink",
    /* 00100 */ "close your eyes",
    /* 01000 */ "jump",
};

std::vector<std::string> secret_handshake::commands(int handshake) {
    std::vector<std::string> cmds;
    for (int i = 0; i < 4; i++) {
        if (handshake & (1 << i)) {
            cmds.emplace_back(actions[i]);
        }
    }
    if (handshake & 0b1'0000) {
        // reverse the order of the operations in the secret handshake
        std::reverse(begin(cmds), end(cmds));
    }
    return cmds;
}
