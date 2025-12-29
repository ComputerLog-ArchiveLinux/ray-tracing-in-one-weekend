#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <vec3.hpp>
#include <Ray.hpp>

#include <cmath>

class Camera {
public:
    vec3 eye;
    vec3 up;
    vec3 direction;
    vec3 spatial_sample_rate;
    vec3 fov;
    float focal_distance;

private:
    vec3 viewport_origin;
    vec3 viewport_right;
    vec3 viewport_up;
    vec3 viewport_pixel_right;
    vec3 viewport_pixel_up;

public:
    // Constructor
    Camera() :
    eye(vec3(0.0f, 0.0f, 0.0f)),
    up(vec3(0.0f, 0.0f, 0.0f)),
    direction(vec3(0.0f, 0.0f, 0.0f)),
    fov(vec3(0.0f, 0.0f)),
    focal_distance(0.0f),
    viewport_origin(vec3(0.0f, 0.0f, 0.0f)),
    viewport_right(vec3(0.0f, 0.0f, 0.0f)),
    viewport_up(vec3(0.0f, 0.0f, 0.0f)),
    viewport_pixel_right(vec3(0.0f, 0.0f, 0.0f)),
    viewport_pixel_up(vec3(0.0f, 0.0f, 0.0f)) {}

    // FOV helper functions
    static vec3 fov_from_horizontal(vec3 spatial_sample_rate, float fov_x) {
        return vec3(
            fov_x,
            2.0f * std::atan(tan(fov_x/2.0f) * spatial_sample_rate[1] / spatial_sample_rate[0])
        );
    }
    static vec3 fov_from_vertical(vec3 spatial_sample_rate, float fov_y) {
        return vec3(
            2.0f * std::atan(tan(fov_y/2.0f) * spatial_sample_rate[0] / spatial_sample_rate[1]),
            fov_y
        );
    }

    // Setup
    void setup() {
        // Normalise directional vectors
        up = vec3::normalise(up);
        direction = vec3::normalise(direction);

        // Viewport coordinates
        viewport_right = vec3::normalise(vec3::cross(direction, up));
        viewport_up    = vec3::normalise(vec3::cross(viewport_right, direction));
        viewport_right *= 2.0f * focal_distance * std::tan(fov[0]/2.0f);
        viewport_up    *= 2.0f * focal_distance * std::tan(fov[1]/2.0f);

        viewport_pixel_right = viewport_right / spatial_sample_rate[0];
        viewport_pixel_up    = viewport_up    / spatial_sample_rate[1];

        viewport_origin = eye + focal_distance * direction;
        viewport_origin += -viewport_right / 2.0f + viewport_up / 2.0f;
        viewport_origin += 0.5f * (viewport_pixel_right - viewport_pixel_up);
    }

    // Generate ray
    Ray gen_ray(float x, float y) {
        vec3 ray_viewport = viewport_origin + x*viewport_pixel_right - y*viewport_pixel_up;
        return Ray(eye, ray_viewport);
    }
};

#endif