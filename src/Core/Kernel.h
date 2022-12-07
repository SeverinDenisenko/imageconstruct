//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_KERNEL_H
#define IMAGECONSTRUCT_KERNEL_H

#include <vector>
#include <iostream>

#include "types.h"

template<typename T>
class Kernel {
public:
    explicit Kernel(size_type size);

    size_type GetSize();

    T& operator()(size_type i, size_type j);
    const T& operator()(size_type i, size_type j) const;

    T& operator()(num_type i, num_type j);
    const T& operator()(num_type i, num_type j) const;
private:
    size_type m_size;
    std::vector<std::vector<T>> m_kernel;
};

template<typename T>
Kernel<T>::Kernel(size_type size) : m_size(size) {

    if (m_size % 2 != 1){
        std::cerr << "Can't create Kernel even size" << std::endl;
    }

    m_kernel = std::vector<std::vector<T>>(m_size);

    for (size_type i = 0; i < m_size; ++i) {
        m_kernel[i] = std::vector<T>(m_size);
    }
}

template<typename T>
size_type Kernel<T>::GetSize() {
    return m_size;
}

template<typename T>
T &Kernel<T>::operator()(size_type i, size_type j) {
    if (i < 0 || i >= m_size || j < 0 || j >= m_size){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    return m_kernel.at(i).at(j);
}

template<typename T>
const T &Kernel<T>::operator()(size_type i, size_type j) const {
    if (i < 0 || i >= m_size || j < 0 || j >= m_size){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    return m_kernel.at(i).at(j);
}

template<typename T>
const T &Kernel<T>::operator()(num_type i, num_type j) const {
    if (i < -(num_type) m_size / 2 || i > (num_type) m_size / 2){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    if (j < -(num_type) m_size / 2 || j > (num_type) m_size / 2){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    return m_kernel.at(i + m_size / 2).at(j + m_size / 2);
}

template<typename T>
T& Kernel<T>::operator()(num_type i, num_type j) {
    if (i < -(num_type) m_size / 2 || i > (num_type) m_size / 2){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    if (j < -(num_type) m_size / 2 || j > (num_type) m_size / 2){
        std::cerr << "Index out of bounds in Kernel" << std::endl;
    }

    return m_kernel.at(i + m_size / 2).at(j + m_size / 2);
}


#endif //IMAGECONSTRUCT_KERNEL_H
