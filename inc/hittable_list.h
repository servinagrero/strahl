#pragma once

#include "hittable.h"

// A hittable_list is just a list of hittable
// It provides great abstraction when calculating hits in a group of objects
class Hittable_list : public Hittable
{
private:
        Hittable **list;
        int list_size;

public:
        Hittable_list() {}
        Hittable_list(Hittable **l, int n)
        {
                list = l;
                list_size = n;
        }
        virtual bool hit(Ray &r, float t_min, float t_max, hit_record &rec) const;
};
