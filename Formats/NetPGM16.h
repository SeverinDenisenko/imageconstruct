//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_NETPGM16_H
#define IMAGECONSTRUCT_NETPGM16_H

#include "../Core/Map.h"

class NetPGM16 : public Map<uint16_t>  {
public:
    NetPGM16(size_type width, size_type height);
    explicit NetPGM16(const Map<uint16_t> &map);
    NetPGM16();

    void Write(const std::string& filename);
    void Read(const std::string& filename);
};


#endif //IMAGECONSTRUCT_NETPGM16_H
