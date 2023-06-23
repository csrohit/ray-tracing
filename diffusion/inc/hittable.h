#ifndef HITTABLE_H
#define HITTABLE_H
/**
 * @file hittable.h
 * @description Abstract class for the objects obstructing a ray
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

#include "ray.h"
#include "vec3.h"
#include <cmath>
#include <utility>

/**
 * @typedef hit_record
 * @brief data for the hit location
 */
typedef struct hit_record
{
    point3 p;               /**< point of intersection */
    vec3 normal;            /**< Unit vector in the direction of p from center (c→p) */
    double t;               /**< value of t for the ray corresponding to point of intersection */
    bool isRayFromOutward;  /**< true if ray is coming from outside the object else false */
} hit_record_t;

/**
 * @class hittable
 * @brief An Abstract class for any which can be hit by a ray
 *
 */
class hittable
{
    public:
        /**
         * @brief 
         *
         * @param r [in] reference to incoming ray object
         * @param t_range [in] acceptable hit range 
         * @param rec [out] reference to hit_record_t
         * @return true if hitting else false 
         */
        virtual bool isHitting(const ray &r, std::pair<double, double> t_range, hit_record_t &rec) const = 0;
};


#endif // !HITTABLE_H
