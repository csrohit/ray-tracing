#ifndef COLOR_H
#define COLOR_H
/**
 * @file color.c
 * @description color utility functions
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
#include <ostream>
inline void write_color(std::ostream &out, color& pixel_color)
{
    out << static_cast<int>(pixel_color[0] * 255.999) << ' ' << static_cast<int>(pixel_color[1] * 255.999)<< ' ' << static_cast<int>(pixel_color[2] * 255.999) << std::endl;
}

#endif // !COLOR_H
