#include "hittable-collection.h"
#include "hittable.h"
#include "ray.h"
#include <utility>
/**
 * @file hittable-collection.cpp
 * @description Implementation for abstract class
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



bool hittableCollection::isHitting(const ray &r, std::pair<double, double>t_range, hit_record_t &rec) const
{
    hit_record_t tmp_rec;
    bool isHit = false;

    for (auto const &obj : objects)
    {
        if(obj->isHitting(r, t_range, tmp_rec))
        {
            isHit = true;
            t_range.second = tmp_rec.t;
            rec = tmp_rec;
        }
    }
    return isHit;
}
