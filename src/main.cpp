#include "Core/TiledMap.h"
#include "Utils.h"
#include "Core/Generators.h"
#include "Core/Filters.h"
#include "Core/Drawer.h"
#include "Formats/NetPGM8.h"

int main() {
    Generators<uint8_t> generators = Generators<uint8_t>();

    size_type size = 256;

    TiledMap<uint8_t> pic = TiledMap<uint8_t>(generators.WhiteNoise(size, size));

    Drawer<uint8_t> drawer = Drawer<uint8_t>();
    drawer.DrawCircle(pic, 20, 20, 15, Color<uint8_t>(0));
    drawer.DrawRectangle(pic, 40, 5, 70, 35, Color<uint8_t>(0));
    drawer.DrawCircle(pic, 20, 60, 15, Color<uint8_t>(Color<uint8_t>::max_value));
    drawer.DrawRectangle(pic, 40, 45, 70, 75, Color<uint8_t>(Color<uint8_t>::max_value));

    Filters<uint8_t>::GaussBlur(pic, 9, 1);
    Filters<uint8_t>::GaussBlur(pic, 9, 1);

    NetPGM8(pic).Write("Images/noise.ppm");
    Utils::Open("Images/noise.ppm");

    return 0;
}
