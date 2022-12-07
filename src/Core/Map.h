//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_MAP_H
#define IMAGECONSTRUCT_MAP_H

#include <vector>
#include <functional>

#include "types.h"
#include "Color.h"

template <typename T>
class Map {
public:
    Map() = default;

    Map(size_type width, size_type height);

    virtual Color<T>& operator()(size_type i, size_type j);
    virtual const Color<T>& operator()(size_type i, size_type j) const;

    void Apply(std::function<Color<T>(size_type i, size_type j)> function);
    void Apply(std::function<Color<T>(void)> function);

    size_type GetWidth();
    size_type GetHeight();

    void SetDepth(size_type depth);
    size_type GetDepth();

    void Clear(size_type width, size_type height, size_type depth);
protected:
    std::vector<std::vector<Color<T>>> m_map;

    size_type m_depth;
    size_type m_width;
    size_type m_height;
};

template<typename T>
Map<T>::Map(size_type width, size_type height) : m_width(width), m_height(height) {
    m_map = std::vector<std::vector<Color<T>>>(m_height);

    for (size_type i = 0; i < m_height; ++i) {
        m_map[i] = std::vector<Color<T>>(m_width);
    }
}

template<typename T>
Color<T> &Map<T>::operator()(size_type i, size_type j) {
    if (i >= m_height || j >= m_width || i < 0 || j < 0){
        std::cerr << "Index out of bounds in Map" << std::endl;
    }

    return m_map.at(i).at(j);
}

template<typename T>
const Color<T> &Map<T>::operator()(size_type i, size_type j) const {
    if (i >= m_height || j >= m_width || i < 0 || j < 0){
        std::cerr << "Index out of bounds in Map" << std::endl;
    }

    return m_map.at(i).at(j);
}

template<typename T>
void Map<T>::SetDepth(size_type depth) {
    m_depth = depth;

    for (auto &row: m_map) {
        for (auto &element: row) {
            element.depth = depth;
        }
    }
}

template<typename T>
void Map<T>::Clear(size_type width, size_type height, size_type depth) {
    m_width = width;
    m_height = height;

    m_map = std::vector<std::vector<Color<T>>>(m_height);

    for (size_type i = 0; i < m_height; ++i) {
        m_map[i] = std::vector<Color<T>>(m_width);
    }

    SetDepth(depth);
}

template<typename T>
size_type Map<T>::GetWidth() {
    return m_width;
}

template<typename T>
size_type Map<T>::GetHeight() {
    return m_height;
}

template<typename T>
void Map<T>::Apply(std::function<Color<T>(size_type i, size_type j)> function) {
    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            (*this)(i, j) = function(i, j);
        }
    }
}

template<typename T>
void Map<T>::Apply(std::function<Color<T>(void)> function) {
    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            (*this)(i, j) = function();
        }
    }
}

template<typename T>
size_type Map<T>::GetDepth() {
    return m_depth;
}


#endif //IMAGECONSTRUCT_MAP_H
