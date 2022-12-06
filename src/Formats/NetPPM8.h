//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_NETPPM8_H
#define IMAGECONSTRUCT_NETPPM8_H

#include "../Core/Map.h"


class NetPPM8 : public Map<uint8_t> {
public:
    NetPPM8(size_type width, size_type height);
    explicit NetPPM8(const Map<uint8_t> &map);
    NetPPM8();

    void Write(const std::string& filename);
    void Read(const std::string& filename);
};


#endif //IMAGECONSTRUCT_NETPPM8_H
