#pragma once

#include <math.h>
#include <iostream>

using namespace std;

class Vec3
{
private:
        float e[3];

public:
        Vec3(){};
        Vec3(float x, float y, float z);
        Vec3(float *coords);
        ~Vec3(){};

        Vec3 operator+();
        Vec3 operator-();
        float operator[](int i) const { return e[i]; };

        Vec3 operator+(const Vec3 &v2);
        Vec3 operator-(const Vec3 &v2);
        Vec3 operator*(const Vec3 &v2);
        Vec3 operator*(const float t);
        Vec3 operator/(const Vec3 &v2);
        Vec3 operator/(const float t);

        Vec3 &operator+=(const Vec3 &v2);
        Vec3 &operator-=(const Vec3 &v2);
        Vec3 &operator*=(const Vec3 &v2);
        Vec3 &operator/=(const Vec3 &v2);
        Vec3 &operator*=(const float t);
        Vec3 &operator/=(const float t);

        float length();
        float squared_length();
        void make_unit_vector();
        Vec3 unit_vector();
};

// Dot product of two vectors
// Operator* v2 just multiplies each of the coordinates of the vector
// Thus we get different result types from these 2 operations
float dot(const Vec3 &v1, const Vec3 &v2);
// Cross product of two vectors
Vec3 cross(const Vec3 &v1, const Vec3 &v2);

std::ostream &operator<<(std::ostream &os, const Vec3 &v);
std::ofstream &operator<<(std::ofstream &os, const Vec3 &v);
