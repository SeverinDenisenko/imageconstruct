#include "Formats/NetPPM8.h"

int main() {

    size_type size = 1024;

    NetPPM8 first = NetPPM8(size, size);
    NetPPM8 second = NetPPM8(size, size);
    NetPPM8 third = NetPPM8(size, size);


    for (size_type i = 0; i < size; ++i) {
        for (size_type j = 0; j < size; ++j) {
            first(i, j) = Color<uint8_t>(UINT8_MAX, 0, 0);
            second(i, j) = Color<uint8_t>(0, UINT8_MAX, 0);
            third(i, j) = first(i, j) + second(i, j);
        }
    }

    first.Write("Images/first.ppm");
    second.Write("Images/second.ppm");
    third.Write("Images/third.pbm");

    return 0;
}
