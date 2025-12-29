#include <vec3.hpp>
#include <Image.hpp>
#include <Camera.hpp>

#include <cmath>

int main() {

    // Setup camera
    Camera camera;
    camera.eye = vec3(0.0f, 0.0f, 0.0f);
    camera.up  = vec3(0.0f, 1.0f, 0.0f);
    camera.direction = vec3(0.0f, 0.0f, -1.0f);
    camera.spatial_sample_rate = vec3(800, 450);
    camera.fov = Camera::fov_from_vertical(camera.spatial_sample_rate, M_PI / 2.0f);
    camera.focal_distance = 1.0f;
    camera.setup();

    // Generate image
    Image img = Image(camera.spatial_sample_rate[0], camera.spatial_sample_rate[1]);
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            // Generate rays
            Ray ray = camera.gen_ray(x, y);

            // Generate pixel color
            float t = vec3::normalise(ray.direction)[1];
            t = 0.5f * (t + 1.0f);
            img[x + y*img.width] = (1.0f-t)*vec3(1.0f, 1.0f, 1.0f) + t*vec3(0.5f, 0.7f, 1.0f);
        }
    }

    // Export image
    img.export_ppm("../gen/img.ppm");
    img.export_png("../gen/img.png");

    return 0;
}