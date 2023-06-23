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
#include <memory>
#include "hittable-collection.h"
#include "hittable.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include "color.h"
#include "camera.h"
#include "common.h"


color ray_color(const ray &r, const hittable &obj, int depth)
{
    if(depth == 0)
        return color(0, 0, 0);
    hit_record_t rec = {};

    if(obj.isHitting(r, std::pair<double, double>(0, infinity), rec))
    {
        point3 target = rec.p + random_in_hemisphere(rec.normal); 
        auto n = rec.normal;
        return 0.5 * ray_color(ray(rec.p, target - rec.p), obj, depth - 1); 
    }
    vec3 unit = r.direction().unit();
    double t = 0.5 * (unit.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main()
{
    const double aspectRatio = 16.0/9.0;
    int depth = 50;
 
    /* image dimentions */
    const int width = 400;
    const int height = width/aspectRatio;

    int samplesPerSecond = 100;
    camera cam;

    /* sphere definition */
    hittableCollection objects;
    objects.add(std::make_shared<sphere>(sphere(point3(0, 0, -1), 0.5)));
    objects.add(std::make_shared<sphere>(sphere(point3(0, -100.5, -2), 100)));
    // objects.add(std::make_shared<sphere>(sphere(point3(2, 3, -1), 0.8)));

    std::cout << "P3\n" << width << " " << height << "\n256\n";

    for(int iy = height - 1; iy >= 0; --iy)
    {
        std::cerr << "\rScanlines remaining: " << iy << ' ' << std::flush;
        for(int ix = 0; ix < width; ++ix)
        {
            color pixel_color(0, 0, 0);
            for(int i=0; i< samplesPerSecond; i++)
            {
                auto scale_x = (ix + random_double()) / (width-1);
                auto scale_y = (iy + random_double()) / (height-1);
                ray r = cam.getRay(scale_x, scale_y);
                pixel_color += ray_color(r, objects, depth);
            }

            /* shoot ray from origin to point */
            write_color(std::cout, pixel_color, samplesPerSecond);
        }
    }
}


