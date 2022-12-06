#include "Formats/NetPGM16.h"
#include "Opener.h"
#include "Generators.h"

int main() {

    // Make white noise
    Map<uint16_t> noise = Generators<uint16_t>::WhiteNoise(64, 64);

    NetPGM16(noise).Write("Images/noise.ppm");

    Opener::Open("Images/noise.ppm");

    return 0;
}
