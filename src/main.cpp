#include <random>

#include "Formats/NetPGM16.h"
#include "Opener.h"

int main() {

    // Make white noise
    NetPGM16 noise = NetPGM16(1024, 1024);

    std::random_device os_seed;
    const uint16_t seed = os_seed();

    std::mt19937 generator( seed );
    std::uniform_int_distribution<uint16_t> distribute( 1, UINT16_MAX );

    std::function<Color<uint16_t>(size_type i, size_type j)> function = [&distribute, &generator](size_type i, size_type j) -> Color<uint16_t> {
        return Color<uint16_t>(distribute(generator));
    };

    noise.Apply(function);

    noise.Write("Images/noise.ppm");

    Opener::Open("Images/noise.ppm");

    return 0;
}
