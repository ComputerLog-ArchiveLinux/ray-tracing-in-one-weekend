#ifndef __PATHTRACER_HPP__
#define __PATHTRACER_HPP__

#include <vec3.hpp>
#include <Ray.hpp>
#include <Camera.hpp>
#include <Image.hpp>

class PathTracer {
public:
    // Constructor
    PathTracer() {}

public:
    Image render(Camera camera) {
        // Prepare image
        Image img = Image(camera.spatial_sample_rate[0], camera.spatial_sample_rate[1]);
        
        // Scene rendering
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

        return img;
    }
};

#endif