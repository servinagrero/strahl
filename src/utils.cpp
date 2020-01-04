#include <functional>
#include <random>

#include "utils.h"
#include "vec.h"

// To calculate a random point in a unit sphere we use the rejection method
// We pick a random point in a unit cube and rejecta point if it is outside a shpere
// Could we use this ??
// https://stackoverflow.com/questions/9600801/evenly-distributing-n-points-on-a-sphere/44164075#44164075
Vec3 random_in_unit_sphere()
{
        Vec3 p;
        do
        {
                p = Vec3(random_double(), random_double(), random_double()) * 2.0 - Vec3(1, 1, 1);
        } while (p.squared_length() >= 1.0);
        return p;
}

// lerp creates a linear blend, or linear interpolation, or lerp between blue
// and white depending on the y value.
// A lerp is of the form: blendedValue = (1−t)∗startValue + t∗endValue
//
// We normalize the direction vector of the ray to scale it's value between 0
// and 1. With that value, we calculate the final color using the lerp.
Vec3 lerp(float *begin, float *end, float t)
{
        Vec3 blend = (Vec3(begin) * (1.0 - t)) + (Vec3(end) * t);
        return blend * 255.99;
}

Vec3 lerp(Vec3 begin, Vec3 end, float t)
{
        Vec3 blend = (begin * (1.0 - t)) + (end * t);
        return blend * 255.99;
}

// Reflect calculathe how a ray reflects from a surface
Vec3 reflect(Vec3 &v, Vec3 &n)
{
        return v - n * (dot(v, n) * 2);
}

double random_double()
{
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;
        static std::function<double()> rand_generator =
            std::bind(distribution, generator);
        return rand_generator();
}
