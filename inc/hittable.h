#pragma once

#include "ray.h"

class Mat;
// A hit record stores:
// At what point in the ray the object was hit
// The position of the ray at the hitpoint
// The normal vector at that point
struct hit_record
{
        float t;
        Vec3 p;
        Vec3 normal;
        Mat *mat_ptr;
};

// A Hittable object is something that can be hit
// hit tells us what the ray does after it has hit an object
class Hittable
{
public:
        virtual bool hit(Ray &r, float t_min, float t_max, hit_record &rec) const = 0;
};
