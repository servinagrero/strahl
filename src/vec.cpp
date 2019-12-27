#include <iostream>
#include <math.h>

#include "vec.h"

using namespace std;

Vec3::Vec3(float x, float y, float z) {
        e[0] = x;
        e[1] = y;
        e[2] = z;
}

Vec3::Vec3(float *coords) {
        e[0] = coords[0];
        e[1] = coords[1];
        e[2] = coords[2];
}

Vec3 Vec3::operator+() {
        return *this;
}

Vec3 Vec3::operator-() {
        return Vec3(-e[0], -e[1], -e[2]);
}

Vec3 Vec3::operator+(const Vec3 &v2) {
    return Vec3(e[0] + v2.e[0], e[1] + v2.e[1], e[2] + v2.e[2]);
}

Vec3 Vec3::operator-(const Vec3 &v2) {
    return Vec3(e[0] - v2.e[0], e[1] - v2.e[1], e[2] - v2.e[2]);
}

Vec3 Vec3::operator*(const Vec3 &v2) {
    return Vec3(e[0] * v2.e[0], e[1] * v2.e[1], e[2] * v2.e[2]);
}

Vec3 Vec3::operator*(const float t) {
    return Vec3(t*e[0], t*e[1], t*e[2]);
}

Vec3 Vec3::operator/(const Vec3 &v2) {
    return Vec3(e[0] / v2.e[0], e[1] / v2.e[1], e[2] / v2.e[2]);
}

Vec3 Vec3::operator/(float t) {
    return Vec3(e[0]/t, e[1]/t, e[2]/t);
}

float Vec3::dot(const Vec3 &v2) {
    return e[0]*v2.e[0] + e[1]*v2.e[1] + e[2]*v2.e[2];
}

Vec3 Vec3::cross(const Vec3 &v2) {
    return Vec3(e[1] * v2.e[2] - e[2] * v2.e[1],
                e[2] * v2.e[0] - e[0] * v2.e[2],
                e[0] * v2.e[1] - e[1] * v2.e[0]);
}

Vec3& Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

Vec3& Vec3::operator/=(const float t) {
    float k = 1.0 / t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

// Length of the vector
float Vec3::length() {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

// Length of the vector but squared
float Vec3::squared_length() {
        return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

// Normalize the vector
void Vec3::make_unit_vector() {
        float k = 1.0 / this->length();
        e[0] *= k; e[1] *= k; e[2] *= k;
}

// Create a normalized copy of the vector
Vec3 Vec3::unit_vector() {
        return (*this / this->length());
}
