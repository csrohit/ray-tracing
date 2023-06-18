#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <ostream>
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


        double length() const
        {
            return std::sqrt(length_squared()); 
        }

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

        vec3 unit()
        {
            return const_cast<const vec3&>(*this)/length();
        }

        double dot(const vec3 &v) const
        {
            return e[0]*v[0] + e[1]*v[1] + e[2]*v[2];
        }

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

using point3 = vec3;
using color = vec3;




#endif // !VEC3_H
