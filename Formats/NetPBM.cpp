//
// Created by Severin on 06.12.2022.
//

#include "NetPBM.h"

#include <fstream>

NetPBM::NetPBM(size_type width, size_type height) : Map(width, height) {
    SetDepth(1);
}

NetPBM::NetPBM(const Map<bool> &map) : Map(map){
    SetDepth(1);
}

void NetPBM::Write(const std::string& filename) {
    std::ofstream out(filename);

    out << "P1" << std::endl;
    out << m_width << " " << m_height << std::endl;

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            out << m_map.at(i).at(j);
        }
    }

    out.close();
}

NetPBM::NetPBM() : Map(){
}

void NetPBM::Read(const std::string &filename) {
    std::ifstream in(filename);

    std::string name;
    in >> name;

    if (name != "P1"){
        std::cerr << "Wrong file format for NetPBM: " << name << std::endl;
    }

    size_type width;
    size_type height;

    in >> width;
    in >> height;

    Clear(width, height, 1);

    for (size_type i = 0; i < m_height; ++i) {
        for (size_type j = 0; j < m_width; ++j) {
            in >> (*this)(i, j);
        }
    }

    in.close();
}
