#include <sstream>

#include "solutions/solutions.h"

std::string toString(const Decimal& dec) {
    std::stringstream ss;
    ss << dec;
    std::string str;
    ss >> str;
    return str;
}