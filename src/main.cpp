#include <iostream>
#include <fstream>

#include "utils.h"
#include "vec.h"
#include "ray.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"

const ssize_t img_width = 800;
const ssize_t img_height = 400;
const ssize_t antialiasing_samples = 100;

int main()
{
        // The output image is a ppm to facilitate the process
        std::ofstream out_file;
        out_file.open("./image.ppm", std::fstream::out | std::fstream::trunc);

        out_file << "P3\n"
                 << img_width << " " << img_height << "\n255\n";

        // The canvas is viewed from a camera
        // This camera is located at the center of the view with the next orientations:
        // Y goes up the canvas; X goes to the right of the canvas; Z goes out of the screen
        //
        // horizontal and vertical are two offset vectors to move the ray across the canvas
        // The bigger they are, the fastest the change in colour occurs
        Vec3 lower_left_corner(-2.0, -1.0, -1.0);
        Vec3 horizontal(4.0, 0.0, 0.0);
        Vec3 vertical(0.0, 2.0, 0.0);
        Vec3 origin(0.0, 0.0, 0.0);

        Hittable *list[4];
        list[0] = new Sphere(Vec3(0, 0, -1), 0.5f, new Lambertian(Vec3(0.8, 0.3, 0.3)));
        list[1] = new Sphere(Vec3(0, -100.5, -1), 100.f, new Lambertian(Vec3(0.8, 0.8, 0.0)));
        list[2] = new Sphere(Vec3(1, 0, -1), 0.5f, new Metal(Vec3(0.8, 0.6, 0.2)));
        list[3] = new Sphere(Vec3(-1, 0, -1), 0.5f, new Metal(Vec3(0.8, 0.8, 0.8)));
        Hittable *world = new Hittable_list(list, 4);

        Camera cam;
        for (int j = img_height - 1; j >= 0; --j)
        {
                for (int i = 0; i < img_width; ++i)
                {
                        Vec3 col(0, 0, 0);
                        for (int s = 0; s < antialiasing_samples; ++s)
                        {
                                float u = float(i + random_double()) / float(img_width);
                                float v = float(j + random_double()) / float(img_height);
                                Ray r = cam.get_ray(u, v);
                                col += r.color(world, 0);
                        }
                        col /= float(antialiasing_samples);

                        // To solve gamma correction problem we calculate the sqrt of the
                        // final color
                        col = col * 255.99;
                        col = Vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );

                        out_file << col << "\n";
                }
        }

        out_file.close();
}
