#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: cannot open input file" << std::endl;
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: cannot create output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << Replace::replaceAll(line, s1, s2) << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}