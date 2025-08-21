#include "secret_handshake.h"

#include <algorithm>

std::vector<std::string> secret_handshake::commands(int handshake) {
    std::vector<std::string> cmds;
    /*
     = wink
     = double blink
     = close your eyes
     = jump
     = 
    */
    const char* decode[] = {
        /* 00001 */ "wink",
        /* 00010 */ "double blink",
        /* 00100 */ "close your eyes",
        /* 01000 */ "jump",
        /* 10000 reverse the order of the operations in the secret handshake */
    };
    for (int i = 0; i < 4; i++) {
        int finger = 1 << i;
        if ((handshake & finger) == finger) {
            cmds.push_back(decode[i]);
        }
    }
    if (handshake & 0b1'0000) {
        std::reverse(cmds.begin(), cmds.end());
    }
    return cmds;
}
