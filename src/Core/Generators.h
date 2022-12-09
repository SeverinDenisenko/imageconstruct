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
    Generators() = default;

    Map<T> WhiteNoise(size_type width, size_type height);

    void RandomSeed();
    void SetSeed(T seed);
private:
    T m_seed = 0;
};

template<typename T>
Map<T> Generators<T>::WhiteNoise(size_type width, size_type height) {
    Map<T> noise = Map<T>(width, height);

    std::mt19937 generator( m_seed );
    std::uniform_int_distribution<T> distribute( 0, std::numeric_limits<T>::max());

    std::function<Color<T>(void)> function = [&distribute, &generator]() -> Color<T> {
        return Color<T>(distribute(generator));
    };

    noise.Apply(function);

    return noise;
}

template<typename T>
void Generators<T>::RandomSeed() {
    std::random_device os_seed;
    m_seed = os_seed();
}

template<typename T>
void Generators<T>::SetSeed(T seed) {
    m_seed = seed;
}


#endif //IMAGECONSTRUCT_GENERATORS_H
