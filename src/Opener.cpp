//
// Created by Severin on 06.12.2022.
//

#include "Opener.h"

void Opener::Open(const std::string& filename) {
    std::system(("open " + filename).c_str());
}
