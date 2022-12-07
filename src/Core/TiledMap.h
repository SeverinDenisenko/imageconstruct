//
// Created by Severin on 07.12.2022.
//

#ifndef IMAGECONSTRUCT_TILEDMAP_H
#define IMAGECONSTRUCT_TILEDMAP_H

#include "Map.h"

template<typename T>
class TiledMap : public Map<T> {
public:
    TiledMap();

    TiledMap(size_type width, size_type height);

    explicit TiledMap(Map<T> map);

    virtual Color<T>& operator()(size_type i, size_type j);
    virtual const Color<T>& operator()(size_type i, size_type j) const;
};

template<typename T>
TiledMap<T>::TiledMap(size_type width, size_type height) : Map<T>(width, height) {

}

template<typename T>
TiledMap<T>::TiledMap() : Map<T>(){

}

template<typename T>
Color<T> &TiledMap<T>::operator()(size_type i, size_type j) {
    return this->m_map.at(i % this->m_height).at(j % this->m_width);
}

template<typename T>
const Color<T> &TiledMap<T>::operator()(size_type i, size_type j) const {
    return this->m_map.at(i % this->m_height).at(j % this->m_width);
}

template<typename T>
TiledMap<T>::TiledMap(Map<T> map) : Map<T>(map) {

}


#endif //IMAGECONSTRUCT_TILEDMAP_H
