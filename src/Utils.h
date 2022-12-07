//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_UTILS_H
#define IMAGECONSTRUCT_UTILS_H

#include <string>

class Utils {
public:
    Utils() = delete;

    static void Open(const std::string& filename);
    static void ToPNG(const std::string& filename, const std::string& result);
};


#endif //IMAGECONSTRUCT_UTILS_H
