//
// Created by Severin on 06.12.2022.
//

#ifndef IMAGECONSTRUCT_COLOR_H
#define IMAGECONSTRUCT_COLOR_H

#include "types.h"
#include <iostream>
#include <fstream>

template<typename T>
class Color {
public:
    Color();
    virtual ~Color();
    explicit Color(T r);
    explicit Color(T r, T g);
    explicit Color(T r, T g, T b);

    virtual Color<T> operator+ (const Color<T> & first) const;
    virtual Color<T> operator- (const Color<T> & first) const;
    virtual Color<T> operator* (const double& first) const;
    virtual Color<T> operator/ (const double& first) const;

    virtual Color<T> operator+= (const Color<T> & first);
    virtual Color<T> operator-= (const Color<T> & first);
    virtual Color<T> operator*= (const double& first);
    virtual Color<T> operator/= (const double& first);

    T r;
    T g;
    T b;

    size_type depth;

    static constexpr T max_value = std::numeric_limits<T>::max();
    static constexpr T min_value = std::numeric_limits<T>::min();
};

template<typename T>
Color<T>::Color() : r(0), g(0), b(0), depth(0) {

}

template<typename T>
Color<T>::Color(T r) : r(r), g(0), b(0), depth(1) {

}

template<typename T>
Color<T>::Color(T r, T g) : r(r), g(g), b(0), depth(2) {

}

template<typename T>
Color<T>::Color(T r, T g, T b) : r(r), g(g), b(b), depth(3) {

}

template<typename T>
Color<T> Color<T>::operator+(const Color<T> &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r + first.r;
    res.g = this->g + first.g;
    res.b = this->b + first.b;

    return res;
}

template<typename T>
Color<T> Color<T>::operator-(const Color<T> &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r - first.r;
    res.g = this->g - first.g;
    res.b = this->b - first.b;

    return res;
}

template<typename T>
Color<T> Color<T>::operator*(const double &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = (double) this->r * first;
    res.g = (double) this->g * first;
    res.b = (double) this->b * first;

    return res;
}

template<typename T>
Color<T> Color<T>::operator/(const double &first) const {
    Color<T> res = Color<T>();
    res.depth = this->depth;

    res.r = this->r / first;
    res.g = this->g / first;
    res.b = this->b / first;

    return res;
}

template<typename T>
Color<T> Color<T>::operator+=(const Color<T> &first) {
    this->r += first.r;
    this->g += first.g;
    this->b += first.b;

    return *this;
}

template<typename T>
Color<T> Color<T>::operator-=(const Color<T> &first) {
    this->r -= first.r;
    this->g -= first.g;
    this->b -= first.b;

    return *this;
}

template<typename T>
Color<T> Color<T>::operator*=(const double &first) {
    this->r *= first;
    this->g *= first;
    this->b *= first;

    return *this;
}

template<typename T>
Color<T> Color<T>::operator/=(const double &first) {
    this->r /= first;
    this->g /= first;
    this->b /= first;

    return *this;
}

template<typename T>
Color<T>::~Color() = default;

template<typename U, typename T>
U& operator<< (U& out, const Color<T> &color) {

    switch (color.depth) {
        case 0:
            break;
        case 1:
            out << +color.r << std::endl;
            break;
        case 2:
            out << +color.r << " " << +color.g << std::endl;
            break;
        case 3:
            out << +color.r << " " << +color.g << " " << +color.b << std::endl;
            break;
        default:
            std::cerr << "Invalid color depth: " << color.depth << std::endl;
    }

    return out;
}

template<typename U, typename T>
U& operator>> (U& in, Color<T> &color) {

    size_type r = 0;
    size_type g = 0;
    size_type b = 0;

    switch (color.depth) {
        case 0:
            break;
        case 1:
            in >> r;
            break;
        case 2:
            in >> r;
            in >> g;
            break;
        case 3:
            in >> r;
            in >> g;
            in >> b;
            break;
        default:
            std::cerr << "Invalid color depth: " << color.depth << std::endl;
    }

    color.r = (T) r;
    color.g = (T) g;
    color.b = (T) b;

    return in;
}

#endif //IMAGECONSTRUCT_COLOR_H
