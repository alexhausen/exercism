#include <string>

namespace log_line {
    std::string message(std::string line) {
        auto n = line.find("]: ");
        if (n != std::string::npos) {
            return line.substr(n + 3);
        }
        return "";
    }

    std::string log_level(std::string line) {
        // return the log level
        if (line.find("[") == 0) {
            if (auto n = line.find("]: "); n != std::string::npos) {
                std::string lvl = line.substr(1, n - 1);
                for (auto& ch : lvl) {
                    ch = std::toupper(ch);
                }
                return lvl;
            }
        }
        return "";
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        return message(line) + " (" + log_level(line) + ")";
    }
}
