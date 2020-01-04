#include "sphere.h"

// The equation of a circle in vector form is:
// dot((p - C), (p - C)) = R^2
// and thus, any point that satisfaies this equation is part of the circle
// We can calculate the relative position of the circle with the amount of roots:
//   0 roots means the ray does not touch the circle
//   1 root means the ray is tangent to the circle
//   2 roots means the ray crosses the circle
// It it just an algebraic equation
//
// The normal vector is perpendicular to the surface of the object.
// In the case of a sphere, this vector is p - C.
// For convenience of shading, the normal vectors are unitary
bool Sphere::hit(Ray &r, float t_min, float t_max, hit_record &rec) const
{
        Vec3 oc = r.origin() - center;
        float a = dot(r.direction(), r.direction());
        float b = dot(oc, r.direction());
        float c = dot(oc, oc) - radius * radius;
        float discriminant = b * b - a * c;

        // If the discriminant is greater than 0 the object is in front of the camera
        if (discriminant > 0)
        {
                float temp = (-b - sqrt(discriminant)) / a;
                if (temp < t_max && temp > t_min)
                {
                        rec.t = temp;
                        rec.p = r.point_at(rec.t);
                        rec.normal = (rec.p - center) / radius;
                        rec.mat_ptr = mat_ptr;
                        return true;
                }
                temp = (-b + sqrt(discriminant)) / a;
                if (temp < t_max && temp > t_min)
                {
                        rec.t = temp;
                        rec.p = r.point_at(rec.t);
                        rec.normal = (rec.p - center) / radius;
                        rec.mat_ptr = mat_ptr;
                        return true;
                }
        }
        return false;
}
