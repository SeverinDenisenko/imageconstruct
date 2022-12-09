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
    void DrawRectangle(TiledMap<T> &map, double x1, double y1, double x2, double y2, Color<T> color);
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

template<typename T>
void Drawer<T>::DrawRectangle(TiledMap<T> &map, double x1, double y1, double x2, double y2, Color<T> color) {
    std::function<void(Color<T>& res, size_type i, size_type j)> f = [&x1, &y1, &x2, &y2, &color](Color<T>& res, size_type i, size_type j){
        if (i > x1 && i < x2 && j > y1 && j < y2){
            res = color;
        }
    };

    map.Apply(f);
}


#endif //IMAGECONSTRUCT_DRAWER_H
