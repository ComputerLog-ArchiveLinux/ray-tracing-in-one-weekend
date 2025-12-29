#include <vec3.hpp>
#include <Image.hpp>
#include <Camera.hpp>
#include <PathTracer.hpp>

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
    PathTracer pathtracer;
    Image img = pathtracer.render(camera);

    // Export image
    img.export_ppm("../gen/img.ppm");
    img.export_png("../gen/img.png");

    return 0;
}