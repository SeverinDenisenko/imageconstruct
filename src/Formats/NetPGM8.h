//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_NETPGM8_H
#define IMAGECONSTRUCT_NETPGM8_H

#include "../Core/Map.h"

/**
 * PGM Stands for Portable Gray Map. Represents image with only gray colors
 */
class NetPGM8 : public Map<uint8_t>  {
public:
    NetPGM8(size_type width, size_type height);
    explicit NetPGM8(const Map<uint8_t> &map);
    NetPGM8();

    void Write(const std::string& filename);
    void Read(const std::string& filename);
};


#endif //IMAGECONSTRUCT_NETPGM8_H
