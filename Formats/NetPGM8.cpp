//
// Created by Severin on 06.12.2022.
//

#include "NetPGM8.h"

NetPGM8::NetPGM8(size_type width, size_type height) : Map(width, height) {
    SetDepth(1);
}

NetPGM8::NetPGM8(const Map<uint8_t> &map) : Map(map) {
    SetDepth(1);
}

void NetPGM8::Write(const std::string& filename) {
    std::ofstream out(filename);

    out << "P2" << std::endl;
    out << m_width << " " << m_height << std::endl;
    out << UINT8_MAX << std::endl;

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            out << m_map.at(i).at(j);
        }
    }

    out.close();
}

NetPGM8::NetPGM8() : Map(){
}

void NetPGM8::Read(const std::string &filename) {
    std::ifstream in(filename);

    std::string name;
    in >> name;

    if (name != "P2"){
        std::cerr << "Wrong file format for NetPGM8: " << name << std::endl;
    }

    size_type width;
    size_type height;

    in >> width;
    in >> height;

    size_type max;
    in >> max;

    if (max != UINT8_MAX){
        std::cerr << "Unsupported max value: " << max << std::endl;
    }

    Clear(width, height, 1);

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            in >> (*this)(i, j);
        }
    }

    in.close();
}
