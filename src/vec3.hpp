#ifndef __VEC3_HPP__
#define __VEC3_HPP__

class vec3 {
public:
    float e[3];

public:
    // Constructor
    vec3() : e{0.0f, 0.0f, 0.0f} {}
    vec3(float e0, float e1) : e{e0, e1, 0.0f} {}
    vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

    // Member access
    float& operator[](int index) { return e[index]; }
};

#endif