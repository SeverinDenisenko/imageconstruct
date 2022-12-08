//
// Created by Severin on 08.12.2022.
//

#ifndef IMAGECONSTRUCT_DRAWER_H
#define IMAGECONSTRUCT_DRAWER_H

#include "TiledMap.h"

template<typename T>
class Drawer {
public:
    Drawer() = default;

    void DrawCircle(TiledMap<T> &map, double x, double y, double size, Color<T> color);
};

template<typename T>
void Drawer<T>::DrawCircle(TiledMap<T> &map, double x, double y, double size, Color<T> color) {
    std::function<void(Color<T>& res, size_type i, size_type j)> f = [&x, &y, &size, &color](Color<T>& res, size_type i, size_type j){
        if ((x - (double)i) * (x - (double)i) + (y - (double)j) * (y - (double)j) < size * size){
            res = color;
        }
    };

    map.Apply(f);
}


#endif //IMAGECONSTRUCT_DRAWER_H
