#include "Replace.hpp"

std::string Replace::replaceAll(const std::string& line, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return line;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos) {
        result += line.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }

    result += line.substr(pos);

    return result;
}