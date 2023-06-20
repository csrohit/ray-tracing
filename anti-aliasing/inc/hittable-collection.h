#ifndef HITTABLE_COLLECTION_H
#define HITTABLE_COLLECTION_H
/**
 * @file hittable-collection.h
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

#include "hittable.h"
#include <memory>
#include <utility>
#include <vector>
class hittableCollection: public hittable
{
    public:
    hittableCollection(){};
    hittableCollection(std::shared_ptr<hittable> obj){add(obj);};
    void add(std::shared_ptr<hittable> obj){objects.push_back(obj);};
    void clear(){objects.clear();};

    virtual bool isHitting(const ray &r, std::pair<double, double> t_range, hit_record_t &rec) const override;

    
    private:    
    std::vector<std::shared_ptr<hittable>> objects;
};

#endif // !HITTABLE_COLLECTION_H
