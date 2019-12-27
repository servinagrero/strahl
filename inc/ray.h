#pragma once
#include "vec.h"

// The equation of a ray is: p(t) = O + D * t
// where O is the origin vector and D is the direction
class Ray {
public:
        Ray() {};
        ~Ray() {};

        Ray(const Vec3& o, const Vec3& d): O(o), D(d) {};
        Vec3 origin() const { return O; };
        Vec3 direction() const { return D; };
        Vec3 point_at(float t);
        Vec3 lerp(float *begin, float *end);
private:
        Vec3 O;
        Vec3 D;
};
