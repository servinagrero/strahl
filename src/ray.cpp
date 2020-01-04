#include <iostream>

#include "ray.h"
#include "hittable.h"
#include "utils.h"
#include "material.h"

// Return a point in the given ray
Vec3 Ray::point_at(float t)
{
        return O + (D * t);
}

// Return the color for the pixel on the screen
//
// To visualize the normal vectors, we map the vector from -1,+1 to 0,+1
// and then map each coordinate to r, g, b
Vec3 Ray::color(Hittable *world, int depth)
{
        hit_record rec;
        static float begin_c[] = {1.f, 1.f, 1.f};
        static float end_c[] = {.5f, .7f, 1.f};

        // For each pixel, we check if the ray has hit at least once
        // We use 0.001 to solve 'acne problem'
        if (world->hit(*this, 0.001, MAXFLOAT, rec))
        {
                Ray scattered;
                Vec3 attenuation;
                if (depth < 50 && rec.mat_ptr->scatter(*this, rec, attenuation, scattered))
                {
                        return attenuation * scattered.color(world, depth + 1);
                }
                else
                {
                        return Vec3(0, 0, 0);
                }
        }
        else
        {
                // We draw the background since there are no hits
                Vec3 unit_direction = D.unit_vector();
                float t = 0.5 * (unit_direction[1] + 1.0);
                return lerp(begin_c, end_c, t);
        }

        return Vec3(0, 0, 0);
}
