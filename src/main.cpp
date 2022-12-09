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

    pic *= 0.1;
    pic += Color<uint8_t>(Color<uint8_t>::max_value / 2);

    Filters<uint8_t>::GaussBlur(pic, 9, 1);
    Filters<uint8_t>::GaussBlur(pic, 9, 1);

    TiledMap<uint8_t> geom = TiledMap<uint8_t>(size, size);
    TiledMap<double> mask = TiledMap<double>(size, size);

    Drawer<uint8_t> drawer = Drawer<uint8_t>();
    drawer.DrawCircle(geom, 20, 20, 15, Color<uint8_t>(0));
    drawer.DrawRectangle(geom, 40, 5, 70, 35, Color<uint8_t>(0));
    drawer.DrawCircle(geom, 20, 60, 15, Color<uint8_t>(Color<uint8_t>::max_value));
    drawer.DrawRectangle(geom, 40, 45, 70, 75, Color<uint8_t>(Color<uint8_t>::max_value));

    Drawer<double> drawer1 = Drawer<double>();
    drawer1.DrawCircle(mask, 20, 20, 15, Color<double>(1.0));
    drawer1.DrawRectangle(mask, 40, 5, 70, 35, Color<double>(1.0));
    drawer1.DrawCircle(mask, 20, 60, 15, Color<double>(1.0));
    drawer1.DrawRectangle(mask, 40, 45, 70, 75, Color<double>(1.0));

    Filters<uint8_t>::GaussBlur(geom, 3, 0.7);
    Filters<uint8_t>::GaussBlur(geom, 3, 0.7);

    Filters<double>::GaussBlur(mask, 3, 0.7);
    Filters<double>::GaussBlur(mask, 3, 0.7);

    pic.Overlay(geom, mask);

    NetPGM8(pic).Write("Images/noise.ppm");
    Utils::Open("Images/noise.ppm");

    return 0;
}
