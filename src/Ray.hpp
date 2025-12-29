#ifndef __RAY_HPP__
#define __RAY_HPP__

#include <vec3.hpp>

class Ray {
public:
    vec3 origin;
    vec3 direction;

public:
    // Constructor
    Ray() : origin(vec3(0.0f, 0.0f, 0.0f)), direction(vec3(0.0f, 0.0f, 0.0f)) {}
    Ray(vec3 _origin, vec3 _direction) : origin(_origin), direction(_direction) {}

    // Fetch point
    vec3 at(float t) { return origin + t*direction; }
};

#endif