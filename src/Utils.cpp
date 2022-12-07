//
// Created by Severin on 06.12.2022.
//

#include "Utils.h"

void Utils::Open(const std::string& filename) {
    std::system(("open " + filename).c_str());
}

void Utils::ToPNG(const std::string& filename, const std::string& result) {
    std::system(("pnmtopng " + filename + " > " + result).c_str());
}
