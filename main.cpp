#include "Formats/NetPPM8.h"
#include "Formats/NetPPM16.h"
#include "Formats/NetPBM.h"

int main() {

    size_type size = 1024;

    NetPPM8 first = NetPPM8(size, size);
    NetPPM16 second = NetPPM16(size, size);
    NetPBM third = NetPBM(size, size);


    for (size_type i = 0; i < size; ++i) {
        for (size_type j = 0; j < size; ++j) {
            first(i, j).r = 123;
            first(i, j).g = 23;
            first(i, j).b = 2;

            second(i, j).r = 1234;
            second(i, j).g = 345;
            second(i, j).b = 12356;

            if (i > size / 2){
                third(i, j).r = true;
            } else {
                third(i, j).r = false;
            }

        }
    }

    first.Write("Images/first.ppm");
    second.Write("Images/second.ppm");
    third.Write("Images/third.pbm");

    return 0;
}
