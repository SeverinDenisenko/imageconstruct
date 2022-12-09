//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_NETPBM_H
#define IMAGECONSTRUCT_NETPBM_H

#include "../Core/Map.h"

/**
 * PBM Stands for Portable Bit Map. Represents image with only tho possible values
 */
class NetPBM : public Map<bool> {
public:
    NetPBM(size_type width, size_type height);
    explicit NetPBM(const Map<bool> &map);
    NetPBM();

    void Write(const std::string& filename);
    void Read(const std::string& filename);
};


#endif //IMAGECONSTRUCT_NETPBM_H
