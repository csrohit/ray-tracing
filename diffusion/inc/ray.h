#ifndef RAY_H
#define RAY_H
#include "vec3.h"
/**
 * @file ray.h
 * @description representation of ray
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

class ray
{
    public:
    ray(){};
    ray(const point3 &origin, const vec3 &direction): org(origin), dir(direction){};

    point3 origin() const { return org;}

    vec3 direction() const { return dir;}

    point3 at(const double t) const { return org + dir * t;}

    private:
    point3 org;
    vec3 dir;
};




#endif // !RAY_H
