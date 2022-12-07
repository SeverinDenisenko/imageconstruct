//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_FILTERS_H
#define IMAGECONSTRUCT_FILTERS_H

#include "Map.h"
#include "Kernel.h"
#include "Operators.h"
#include "TiledMap.h"


template<typename T>
class Filters {
public:
    Filters() = delete;

    static void GaussBlur3(Map<T> &map);
    static void GaussBlur3(TiledMap<T> &map);
};

template<typename T>
void Filters<T>::GaussBlur3(Map<T> &map) {
    Kernel<double> kernel = Kernel<double>(3);

    kernel(0u, 0u) = 1.0/16;
    kernel(0u, 2u) = 1.0/16;
    kernel(2u, 0u) = 1.0/16;
    kernel(2u, 2u) = 1.0/16;

    kernel(1u, 0u) = 1.0/8;
    kernel(0u, 1u) = 1.0/8;
    kernel(1u, 2u) = 1.0/8;
    kernel(2u, 1u) = 1.0/8;

    kernel(2u, 2u) = 1.0/4;

    Operators<T>::Convolution(map, kernel);
}

template<typename T>
void Filters<T>::GaussBlur3(TiledMap<T> &map) {
    Kernel<double> kernel = Kernel<double>(3);

    kernel(0u, 0u) = 1.0/16;
    kernel(0u, 2u) = 1.0/16;
    kernel(2u, 0u) = 1.0/16;
    kernel(2u, 2u) = 1.0/16;

    kernel(1u, 0u) = 1.0/8;
    kernel(0u, 1u) = 1.0/8;
    kernel(1u, 2u) = 1.0/8;
    kernel(2u, 1u) = 1.0/8;

    kernel(2u, 2u) = 1.0/4;

    Operators<T>::Convolution(map, kernel);
}

#endif //IMAGECONSTRUCT_FILTERS_H
