#pragma once

#include "ray.h"

// Camera represents the main viewpoint of the raycaster
class Camera
{
private:
        Vec3 origin;            // The actual position of the camera
        Vec3 lower_left_corner; // The lower left corner of the screen
        Vec3 horizontal;
        Vec3 vertical;

public:
        Camera()
        {
                origin = Vec3(0.0, 0.0, 0.0);
                lower_left_corner = Vec3(-2.0, -1.0, -1.0);
                horizontal = Vec3(4.0, 0.0, 0.0);
                vertical = Vec3(0.0, 2.0, 0.0);
        }
        Camera(Vec3 o, Vec3 l, Vec3 h, Vec3 v) : origin(o), lower_left_corner(l), horizontal(h), vertical(v)
        {
        }

        Ray get_ray(float u, float v)
        {
                return Ray(origin, lower_left_corner + horizontal * u + vertical * v - origin);
        }
};
