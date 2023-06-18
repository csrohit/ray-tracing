#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <ostream>
inline void write_color(std::ostream &out, color& pixel_color)
{
    out << static_cast<int>(pixel_color[0] * 255.999) << ' ' << static_cast<int>(pixel_color[1] * 255.999)<< ' ' << static_cast<int>(pixel_color[2] * 255.999) << std::endl;
}

#endif // !COLOR_H
