#include "Formats/NetPGM16.h"
#include "Core/TiledMap.h"
#include "Utils.h"
#include "Core/Generators.h"
#include "Core/Operators.h"
#include "Core/Filters.h"
#include "Core/Kernel.h"

int main() {

    // Make white noise
    TiledMap<uint16_t> noise = TiledMap<uint16_t>(Generators<uint16_t>::WhiteNoise(256, 256));

    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);
    Filters<uint16_t>::GaussBlur(noise, 7);

    NetPGM16(noise).Write("Images/noise.ppm");
    Utils::ToPNG("Images/noise.ppm", "Images/noise.png");

    Utils::Open("Images/noise.png");

    return 0;
}
