/**
 * @file sphere.cpp
 * @description Sphere implementation 
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
#include "sphere.h"
#include "hittable.h"
#include <cmath>


/**
 * @brief Check if ray is hitting the sphere
 *
 * @param r reference to the ray
 * @param t_range range of acceptable positions on the ray
 *           - so as not to trace the ray till infinity
 * @param rec reference to hit_record_t
 * @return true if ray is hitting the sphere in acceptable range else false
 */
bool sphere::isHitting(const ray &r, std::pair<double, double> t_range, hit_record_t &rec) const
{
    /* equation for descriminant had 2 in numerator and denominator so improvising */
    const vec3 oc = r.origin() - center;
    const double a = r.direction().length_squared();
    const double half_b = r.direction().dot(oc);   
    const double c = oc.dot(oc) - radius*radius;   
    auto descriminant =  half_b*half_b - a*c;

    if(descriminant < 0)
    {
        /* non-real roots */
        return false;
    }
    else
    {
        /* real and non-equal roots */
        auto sqrt_descriminant = std::sqrt(descriminant);
        auto root = (-half_b - sqrt_descriminant)/a;
        if(root < t_range.first || root > t_range.second)
        {
            /* root1 is not in range<min, max> */
            root = (-half_b + sqrt_descriminant)/a;
            if(root < t_range.first || root > t_range.second)
            {
                /**
                 * root2 is also not in range<min, max>
                 * - even if the roots are real but not in range so return false
                 *   (no-intersection found in given range)
                 */
                return false;
            }
        }
        rec.t = root;
        rec.p = r.at(root);
        rec.normal = (rec.p - center)/radius;
        if(rec.normal.dot(r.direction()) < 0)
        {
            /**
             * if ray and normal have angle between -90→90 then dot product is positive
             *  i.e. in same direction dot product is positive (a.b = ab*cos(θ))
             */
            rec.isRayFromOutward = true;
        }
        else
        {
            rec.isRayFromOutward = false;
            
            /* ray and normal should point away from each other (by design) */
            rec.normal = -rec.normal;
        }
    }
    return (-half_b - std::sqrt(descriminant))/a ;
}
