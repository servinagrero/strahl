#include <iostream>
#include <fstream>

#include "vec.h"
#include "ray.h"

const ssize_t img_width = 1024;
const ssize_t img_height = 720;

// To output the image we are using the ppm format
// "P3" means this is a RGB color image in ASCII
// "WIDTH HEIGHT" is the width and height of the image in pixels
// "255" is the maximum value for each color
// The part below is image data: RGB triplets
int main() {
    std::ofstream out_file;
    out_file.open("./image.ppm", std::fstream::out | std::fstream::trunc);

    out_file << "P3\n" << img_width << " " << img_height << "\n255\n";

    // The canvas is viewed from a camera
    // This camera is located at the center of the camera with the next orientations:
    // Y goes up the canvas; X goes to the right of the canvas; Z goes out of the screen
    //
    // horizontal and vertical are two offset vectors to move the ray across the canvas
    // The bigger they are, the fastest the change in colour occurs
    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(1.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    float white_c[] = {0.f, 0.f, 0.f};
    float black_c[] = {1.f, 1.f, 1.f};

    for (int j = img_height-1; j >= 0; --j) {
        for (int i = 0; i < img_width; ++i) {
                float u = float(i) / float(img_width);
                float v = float(j) / float(img_height);

                Ray r(origin, lower_left_corner + (horizontal*u) + (vertical*v));
                Vec3 col = r.lerp(white_c, black_c);
                int ir = int(255.99*col[0]);
                int ig = int(255.99*col[1]);
                int ib = int(255.99*col[2]);

                out_file << ir << " " << ig << " " << ib << "\n";
        }
    }

    out_file.close();
}
