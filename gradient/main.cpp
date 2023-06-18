#include <iostream>
#include "vec3.h"
#include "color.h"



int main()
{
    const int image_height = 256;
    const int image_width = 256;
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int ig = image_height - 1; ig >= 0; --ig)
    {
        for(int ir = 0; ir < image_width; ++ir)
        {
            color pixel_color(double(ig)/(image_width - 1), double(ir)/(image_height - 1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }

    return (0);
}


