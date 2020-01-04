#pragma once

#include "vec.h"

class Hittable;

// Ray represents a ray of light
// Its equation is: p(t) = O + D * t where
// O is the origin vector, D is the direction and t a point along the ray
class Ray
{
private:
        Vec3 O;
        Vec3 D;

public:
        Ray(){};
        ~Ray(){};
        Ray(const Vec3 &o, const Vec3 &d) : O(o), D(d){};

        Vec3 origin() const { return O; };
        Vec3 direction() const { return D; };
        Vec3 point_at(float t);
        Vec3 color(Hittable *world, int depth);
};
