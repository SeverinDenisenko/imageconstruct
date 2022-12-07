//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_GENERATORS_H
#define IMAGECONSTRUCT_GENERATORS_H

#include <random>

#include "Map.h"

template<typename T>
class Generators {
public:
    Generators() = delete;

    static Map<T> WhiteNoise(size_type width, size_type height);
};

template<typename T>
Map<T> Generators<T>::WhiteNoise(size_type width, size_type height) {
    Map<T> noise = Map<T>(width, height);

    std::random_device os_seed;
    const T seed = os_seed();

    std::mt19937 generator( seed );
    std::uniform_int_distribution<T> distribute( 0, std::numeric_limits<T>::max());

    std::function<Color<T>(void)> function = [&distribute, &generator]() -> Color<uint16_t> {
        return Color<T>(distribute(generator));
    };

    noise.Apply(function);

    return noise;
}


#endif //IMAGECONSTRUCT_GENERATORS_H
