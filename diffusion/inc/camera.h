#ifndef CAMERA_H
#define CAMERA_H
/**
 * @file camera.h
 * @description camera definition
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

#include "vec3.h"
#include "ray.h"
class camera
{
    public:
        camera()
        {
            auto aspectRatio    = 16.0/9.0;
            auto viewportHeight = 2.0;
            auto viewportWidth  = aspectRatio * viewportHeight;
            auto focalLength    = 1.0;

            origin      = point3(0, 0, 0);
            horizontal  = vec3(viewportWidth, 0.0, 0.0);
            vertical    = vec3(0.0, viewportHeight, 0.0);
            bottomLeft  = origin - horizontal/2 - vertical/2 - vec3(0.0, 0.0, focalLength);
        }

        ray getRay(double x, double y) const
        {
            return ray(origin, bottomLeft + x*horizontal + y*vertical - origin);
        }

    private:
        point3 origin;
        point3 bottomLeft;
        vec3 horizontal;
        vec3 vertical;
};


#endif // !CAMERA_H
