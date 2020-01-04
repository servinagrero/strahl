#pragma once

#include "hittable.h"

// The Sphere is the basic testing shape for the raytracer
// since it has the 'easiest' formula
class Sphere : public Hittable
{
private:
        Vec3 center;
        float radius;
        Mat *mat_ptr;

public:
        Sphere(){};
        Sphere(Vec3 cen, float r, Mat *m) : center(cen), radius(r), mat_ptr(m){};
        Sphere(Vec3 c, float r) : center(c), radius(r){};
        virtual bool hit(Ray &r, float t_min, float t_max, hit_record &rec) const;
};
