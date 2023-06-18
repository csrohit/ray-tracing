#include <cmath>
#include <iostream>
#include "ray.h"
#include "vec3.h"
#include "color.h"

color ray_color(const ray &ray)
{
    vec3 unit = ray.direction().unit();
    auto t = 0.5 * (unit.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


int main()
{
    const double aspectRatio = 16.0/9.0;
    const int width = 400;
    const int height = static_cast<int>(width/aspectRatio);
    
    double viewport_height = 2.0;
    double viewport_width = aspectRatio * viewport_height;
    double focalLength = 1.0;

    point3 origin(0.0, 0.0, 0.0);
    point3 horizontal(viewport_width, 0.0, 0.0);
    point3 vertical(0.0, viewport_height, 0.0);
    point3 bottomLeft = origin - horizontal/2 - vertical/2 - vec3(0.0, 0.0, focalLength);
    

    std::cout << "P3\n" << width << ' ' << height << "\n255\n";
    
    for(int i=height - 1; i>= 0; --i)
    {
        for (int j = 0; j < width; j++) {
            auto u = double(j)/(width - 1);
            auto v = double(i)/(height - 1);

            ray r(origin, bottomLeft + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }



    return (0);
}


