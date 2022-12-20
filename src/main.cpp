#include "Core/TiledMap.h"
#include "Utils.h"
#include "Core/Generators.h"
#include "Core/Filters.h"
#include "Core/Drawer.h"
#include "Formats/NetPGM16.h"

int main() {
    size_type size = 512;

    TiledMap<uint16_t> pic = TiledMap<uint16_t>(512, 512);

    TiledMap<uint16_t> geom_layer = TiledMap<uint16_t>(512, 512);
    TiledMap<double> mask_layer = TiledMap<double>(512, 512);

    Drawer<uint16_t> geom_drawer = Drawer<uint16_t>();
    geom_drawer.DrawRectangle(geom_layer, 0, 0, 100, 100, Color<uint16_t>(Color<uint16_t>::max_value));
    geom_drawer.DrawRectangle(geom_layer, 200, 200, 300, 300, Color<uint16_t>(Color<uint16_t>::max_value));

    Drawer<double> mask_drawer = Drawer<double>();
    mask_drawer.DrawRectangle(mask_layer, 0, 0, 100, 100, Color<double>(1));
    mask_drawer.DrawRectangle(mask_layer, 200, 200, 300, 300, Color<double>(1));

    Filters<uint16_t>::GaussBlur(geom_layer, 9, 0.7);
    Filters<double>::GaussBlur(mask_layer, 9, 0.7);

    pic.Overlay(geom_layer, mask_layer);

    mask_layer.Fill(Color<double>(0));
    Generators<uint16_t> generators = Generators<uint16_t>();
    TiledMap<uint16_t> noise = TiledMap<uint16_t>(generators.WhiteNoise(size, size));
    mask_drawer.DrawRectangle(mask_layer, 300, 0, 400, 100, Color<double>(1));
    pic.Overlay(noise, mask_layer);

    mask_layer.Fill(Color<double>(0));
    Filters<uint16_t>::GaussBlur(noise, 13, 3);
    mask_drawer.DrawRectangle(mask_layer, 0, 300, 100, 400, Color<double>(1));
    pic.Overlay(noise, mask_layer);

    NetPGM16(pic).Write("Images/noise.ppm");
    Utils::Open("Images/noise.ppm");

    return 0;
}
