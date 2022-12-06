#include "Formats/NetPPM8.h"

int main() {

    NetPPM8 first = NetPPM8();

    first.Read("Images/first.ppm");

    size_type size = first.GetHeight();

    std::cout << size << std::endl;

    first.Write("Images/readed.ppm");

    return 0;
}
