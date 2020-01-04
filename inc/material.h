#pragma once

#include "ray.h"
#include "utils.h"
#include "hittable.h"

// Mat represents the material that the object is made of
class Mat
{
public:
        virtual bool scatter(const Ray &r_in, hit_record &rec,
                             Vec3 &attenuation, Ray &scattered) const = 0;
};

// Lambertian reflectance is the property that defines an ideal "matte" or diffusely reflecting surface.
class Lambertian : public Mat
{
private:
        // Albedo is the diffuse reflection out of the total radiation recieved by an object
        Vec3 albedo;

public:
        Lambertian(const Vec3 &a) : albedo(a) {}
        virtual bool scatter(const Ray &r_in, hit_record &rec,
                             Vec3 &attenuation, Ray &scattered) const
        {
                (void)r_in;
                Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
                scattered = Ray(rec.p, target - rec.p);
                attenuation = albedo;
                return true;
        }
};

// Metal is any material with a polished surface
class Metal : public Mat
{
private:
        Vec3 albedo;

public:
        Metal(const Vec3 &a) : albedo(a) {}
        virtual bool scatter(const Ray &r_in, hit_record &rec,
                             Vec3 &attenuation, Ray &scattered) const
        {
                Vec3 r_in_dir = r_in.direction().unit_vector();
                Vec3 reflected = reflect(r_in_dir, rec.normal);
                scattered = Ray(rec.p, reflected);
                attenuation = albedo;
                return (dot(scattered.direction(), rec.normal) > 0);
        }
};
