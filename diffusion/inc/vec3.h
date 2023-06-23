#ifndef VEC3_H
#define VEC3_H
/**
 * @file vec3.h
 * @description representation of 3D vector class
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

#include "common.h"
#include <iostream>
#include <cmath>
#include <ostream>


/**
 * @class vec3
 * @brief Representation of 3D vector 
 */
class vec3
    {
    private:
        double e[3];

    public:
        vec3(): e{0,0,0}{};
        vec3(double e0, double e1, double e2): e{e0, e1, e2}{};
        double x() const {return (e[0]);};
        double y() const {return (e[1]);};
        double z() const {return (e[2]);};

        inline static vec3 random()
        {
            return vec3(random_double(), random_double(), random_double());  
        }

        inline static vec3 random(double min, double max)
        {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }


        vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);};
        double operator[](int i) const {return e[i];};
        double& operator[](int i) {return e[i];};

        vec3& operator+=(const vec3 &v)
        {
            e[0] += v[0];
            e[1] += v[1];
            e[2] += v[2];
            return *this;
        }

        vec3& operator*=(const double t)
        {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t)
        {
            *this *= 1/t;
            return *this;
        }

        /**
         * @brief Get magnitude of vector
         *
         * @return 
         */
        double length() const
        {
            return std::sqrt(length_squared()); 
        }

        /**
         * @brief Get the squared magnitude of vector
         *
         * @return 
         */
        double length_squared() const
        {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        friend inline std::ostream& operator<<(std::ostream &out, const vec3 &v)
        {
            return out << v[0] << " " << v[1] << " " << v[2];
        }

        vec3 operator+(const vec3 &v1) const
        {   
            return vec3(e[0]+v1[0], e[1]+v1[1], e[2]+v1[2]);
        }

        vec3 operator-(const vec3 &v1) const
        {   
            return vec3(e[0]-v1[0], e[1]-v1[1], e[2]-v1[2]);
        }

        vec3 operator*(const vec3 &v1) const
        {   
            return vec3(e[0]*v1[0], e[1]*v1[1], e[2]*v1[2]);
        }

        vec3 operator*(const double t) const
        {
            return vec3(e[0]*t, e[1]*t, e[2]*t);
        }

        vec3 operator/(const double t) const
        {
            return *this * (1/t);
        }

        /**
         * @brief Get an unit vector in the direction of current vector
         * @return 
         */
        vec3 unit()
        {
            return const_cast<const vec3&>(*this)/length();
        }

        /**
         * @brief Dot product with another vector
         *
         * @param v other 3d vector
         * @return result of dot product
         */
        double dot(const vec3 &v) const
        {
            return e[0]*v[0] + e[1]*v[1] + e[2]*v[2];
        }

        /**
         * @brief Cross product with another vector
         *
         * @param v other 3d vector
         * @return result of cross product
         */
        vec3 cross(const vec3 &v) const
        {
            return vec3(e[1]*v[2] - v[1]*e[2], -e[0]*v[2] + v[0]*e[2], e[0]*v[1] - v[0]*e[1]);
        }

    };

inline vec3 operator*(const double t, const vec3 &v)
{
    return v * t;
}

inline vec3 operator/(const double t, const vec3 &v)
{
    return v * (1/t);
}

/**
 * @brief Get a radom point in a uni sphere
 *
 * @return 
 */
vec3 randomInUnitSphere()
{
    while(1)
    {
        auto p = vec3::random(-1, 1);
        if(p.length_squared() <= 1)
            return p;
    }
}

using point3 = vec3;
using color = vec3;




#endif // !VEC3_H
