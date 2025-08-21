#include "gigasecond.h"

namespace gigasecond {
    
ptime advance(ptime t) {
    return t + seconds{1'000'000'000};
}
    
}  // namespace gigasecond
