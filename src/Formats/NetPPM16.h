//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_NETPPM16_H
#define IMAGECONSTRUCT_NETPPM16_H

#include <string>

#include "../Core/Map.h"

/**
 * PPM Stands for Portable Pixel Map. Represents colorful RGB image.
 */
class NetPPM16 : public Map<uint16_t> {
public:
    NetPPM16(size_type width, size_type height);
    NetPPM16();
    explicit NetPPM16(const Map<uint16_t> &map);

    void Write(const std::string& filename);
    void Read(const std::string& filename);
};


#endif //IMAGECONSTRUCT_NETPPM16_H
