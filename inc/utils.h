#pragma once

#include "vec.h"

Vec3 random_in_unit_sphere();
Vec3 lerp(Vec3 begin, Vec3 end, float t);
Vec3 lerp(float *begin, float *end, float t);
Vec3 reflect(Vec3& v, Vec3& n);
double random_double();
