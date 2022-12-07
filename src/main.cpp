#include "Formats/NetPGM16.h"
#include "Core/TiledMap.h"
#include "Opener.h"
#include "Core/Generators.h"
#include "Core/Operators.h"
#include "Core/Filters.h"
#include "Core/Kernel.h"

int main() {

    // Make white noise
    TiledMap<uint16_t> noise = TiledMap<uint16_t>(Generators<uint16_t>::WhiteNoise(256, 256));

    NetPGM16(noise).Write("Images/white_noise.ppm");
    Opener::Open("Images/white_noise.ppm");

    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);
    Filters<uint16_t>::GaussBlur3(noise);

    NetPGM16(noise).Write("Images/noise.ppm");
    Opener::Open("Images/noise.ppm");

    return 0;
}
