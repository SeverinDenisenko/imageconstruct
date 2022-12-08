//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_KERNELCOLLECTION_H
#define IMAGECONSTRUCT_KERNELCOLLECTION_H

#include <cmath>
#include "Kernel.h"


template<typename T>
class KernelCollection {
public:
    KernelCollection() = delete;

    static Kernel<T> GaussBlur(size_type size, T sigma);
};

template<typename T>
Kernel<T> KernelCollection<T>::GaussBlur(size_type size, T sigma) {
    Kernel<T> kernel = Kernel<T>(size);

    T s = 2.0 * sigma * sigma;
    T sum = 0;

    for (num_type i = -(num_type) size / 2; i <= (num_type) size / 2; ++i) {
        for (num_type j = -(num_type) size / 2; j <= (num_type) size / 2; ++j) {
            double r = sqrt(i * i + j * j);
            kernel(i, j) = (exp(-(r * r) / s)) / (M_PI * s);
            sum += kernel(i, j);
        }
    }

    for (num_type i = -(num_type) size / 2; i <= (num_type) size / 2; ++i) {
        for (num_type j = -(num_type) size / 2; j <= (num_type) size / 2; ++j) {
            kernel(i, j) /= sum;
        }
    }

    return kernel;
}


#endif //IMAGECONSTRUCT_KERNELCOLLECTION_H
