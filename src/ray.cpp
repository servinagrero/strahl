#include <iostream>

#include "ray.h"

// lerp creates a linear blend, or linear interpolation, or lerp between blue
// and white depending on the y value.
// A lerp is of the form: blendedValue = (1−t)∗startValue + t∗endValue
//
// We normalize the direction vector of the ray to scale it's value between 0
// and 1. With that value, we calculate the final color using the lerp.
Vec3 Ray::lerp(float *begin, float *end) {
        // Scale the height
        Vec3 unit_direction = D.unit_vector();
        float t = 0.5 * (unit_direction[1] + 1.0);

        // Calculate the lerp (White * (1-t) + Blue * t)
        return (Vec3(begin) * (1.0 - t)) + (Vec3(end) * t);
}

// Return a point in the given ray
Vec3 Ray::point_at(float t) {
        return O + (D * t);
}
