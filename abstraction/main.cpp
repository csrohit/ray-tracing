/**
 * @file main.cpp
 * @description Draw a sphere using raytracing
 *
 * @author Rohit Nimkar
 * @verion 1.0
 * @date 2023-06-18
 *
 * @copyright Copyright 2023 Rohit Nimkar
 * @attention
 *  Use of this source code is governed by a BSD-style
 *  license that can be found in the LICENSE file or at
 *  opensource.org/licenses/BSD-3-Clause
 */ 
#include <cmath>
#include <iostream>
#include "hittable.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include "color.h"


color ray_color(const ray &r, const sphere &s)
{
    hit_record_t rec = {};

    if(s.isHitting(r, std::pair<double, double>(0, 100.0), rec))
    {
        auto n = rec.normal;
        return 0.5 * color(n.x()+1, n.y()+1, n.z()+1);
    }
    vec3 unit = r.direction().unit();
    double t = 0.5 * (unit.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main()
{
    const double aspectRatio = 16.0/9.0;
 
    /* image dimentions */
    const int img_width  = 400;
    const int img_height = img_width/aspectRatio;

    double viewport_height = 2.0;
    double viewport_width  = viewport_height * aspectRatio;
    double focal_length    = 1.0;

    point3 origin(0.0, 0.0, 0.0);
    vec3   horizontal(viewport_width, 0.0, 0.0);
    vec3   vertical(0.0, viewport_height, 0.0);
    point3 bottom_left = origin - horizontal/2 - vertical/2 - vec3(0.0, 0.0, focal_length);

    /* sphere definition */
    point3 center = point3(0, 0, -1);
    sphere s(center, 0.5);

    std::cout << "P3\n" << img_width << " " << img_height << "\n256\n";

    for(int iy = img_height - 1; iy >= 0; --iy)
    {
        for(int ix = 0; ix < img_width; ++ix)
        {
            double scale_x = (double) ix/ img_width;
            double scale_y = (double)iy/img_height;

            /* shoot ray from origin to point */
            ray r(point3(0.0, 0.0, 0.0), bottom_left + scale_y*vertical + scale_x*horizontal - origin);
            color pixel_color = ray_color(r, s);
            write_color(std::cout, pixel_color);
        }
    }

}


