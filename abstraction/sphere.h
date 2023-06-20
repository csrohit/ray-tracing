#ifndef _SPHERE_H_
#define _SPHERE_H_
/**
 * @file sphere.h
 * @description Sphere representation
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

#include "hittable.h"
#include "vec3.h"

/**
 * @class sphere
 * @brief 
 *
 */
class sphere: public hittable
{
    public:

    /**
     * @brief unparameterised default constructor
     */
    sphere() = delete;

    /**
     * @brief Parameterized constructor
     *
     * @param c [in] center of the circle
     * @param r [in] radius of the circle
     */
    sphere(point3 c, const double r): center(c), radius(r){};     

    
    bool isHitting(const ray &r, std::pair<double, double> t_range, hit_record_t &rec) const;

    private:
        point3 center; /**< center of the circle */
        double radius; /**< radius of the circle */
};


#endif // !_SPHERE_H_
//
