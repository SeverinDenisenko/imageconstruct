#include "Formats/NetPPM16.h"
#include "Core/TiledMap.h"
#include "Utils.h"
#include "Core/Generators.h"
#include "Core/Operators.h"
#include "Core/Filters.h"
#include "Core/Kernel.h"
#include "Core/Drawer.h"

int main() {
    // Make white noise
    TiledMap<uint16_t> pic = TiledMap<uint16_t>(64, 64);
    pic.Fill(Color<uint16_t>(0, 0, Color<uint16_t>::max_value));

    Drawer<uint16_t> drawer = Drawer<uint16_t>();

    drawer.DrawCircle(pic, 31.5, 31.5, 20, Color<uint16_t>(Color<uint16_t>::max_value, 0, 0));

    Filters<uint16_t>::GaussBlur(pic, 13, 10);

    NetPPM16(pic).Write("Images/noise.ppm");
    Utils::ToPNG("Images/noise.ppm", "Images/noise.png");

    Utils::Open("Images/noise.png");

    return 0;
}
