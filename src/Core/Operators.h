//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_OPERATORS_H
#define IMAGECONSTRUCT_OPERATORS_H

#include "Map.h"
#include "Kernel.h"

template<typename T>
class Operators {
public:
    Operators() = delete;

    template<typename U>
    static void Convolution(TiledMap<T>& image, Kernel<U>& kernel);

    template<typename U>
    static void Convolution(Map<T>& image, Kernel<U>& kernel);
};

template<typename T>
template<typename U>
void Operators<T>::Convolution(TiledMap<T>& image, Kernel<U>& kernel) {
    TiledMap<T> result = TiledMap<T>(image.GetWidth(), image.GetHeight());
    result.SetDepth(image.GetDepth());

    num_type image_height = image.GetHeight();
    num_type image_with = image.GetWidth();

    num_type kernel_size = kernel.GetSize();

    for (num_type i = 0; i < image_height; ++i) {
        for (num_type j = 0; j < image_with; ++j) {

            for (num_type k = -kernel_size / 2; k <= kernel_size / 2; ++k) {
                for (num_type l = -kernel_size / 2; l <= kernel_size / 2; ++l) {

                    result(i, j) += image(i + k, j + l) * kernel(k, l);
                }
            }
        }
    }

    image = result;
}

template<typename T>
template<typename U>
void Operators<T>::Convolution(Map<T>& image, Kernel<U>& kernel) {
    Map<T> result = Map<T>(image.GetWidth(), image.GetHeight());
    result.SetDepth(image.GetDepth());

    num_type image_height = image.GetHeight();
    num_type image_with = image.GetWidth();

    num_type kernel_size = kernel.GetSize();

    for (num_type i = 0; i < image_height; ++i) {
        for (num_type j = 0; j < image_with; ++j) {

            for (num_type k = -kernel_size / 2; k <= kernel_size / 2; ++k) {
                for (num_type l = -kernel_size / 2; l <= kernel_size / 2; ++l) {

                    if (i + k < 0 || i + k >= image_height){
                        continue;
                    }

                    if (j + l < 0 || j + l >= image_with){
                        continue;
                    }

                    result(i, j) += image(i + k, j + l) * kernel(k, l);
                }
            }
        }
    }

    image = result;
}


#endif //IMAGECONSTRUCT_OPERATORS_H
