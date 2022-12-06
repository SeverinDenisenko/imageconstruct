//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_OPENER_H
#define IMAGECONSTRUCT_OPENER_H

#include <string>

class Opener {
public:
    Opener() = delete;

    static void Open(const std::string& filename);
};


#endif //IMAGECONSTRUCT_OPENER_H
