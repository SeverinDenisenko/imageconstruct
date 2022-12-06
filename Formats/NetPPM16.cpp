//
// Created by Severin on 06.12.2022.
//

#include "NetPPM16.h"

#include <fstream>

NetPPM16::NetPPM16(size_type width, size_type height) : Map(width, height) {
    SetDepth(3);
}

NetPPM16::NetPPM16(const Map<uint16_t> &map) : Map(map){
    SetDepth(3);
}

void NetPPM16::Write(const std::string& filename) {
    std::ofstream out(filename);

    out << "P3" << std::endl;
    out << m_width << " " << m_height << std::endl;
    out << UINT16_MAX << std::endl;

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            out << m_map.at(i).at(j);
        }
    }

    out.close();
}

NetPPM16::NetPPM16() : Map(){
}

void NetPPM16::Read(const std::string &filename) {
    std::ifstream in(filename);

    std::string name;
    in >> name;

    if (name != "P3"){
        std::cerr << "Wrong file format for NetPPM16: " << name << std::endl;
    }

    size_type width;
    size_type height;

    in >> width;
    in >> height;

    size_type max;
    in >> max;

    if (max != UINT16_MAX){
        std::cerr << "Unsupported max value: " << max << std::endl;
    }

    Clear(width, height, 3);

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            in >> (*this)(i, j);
        }
    }

    in.close();
}
