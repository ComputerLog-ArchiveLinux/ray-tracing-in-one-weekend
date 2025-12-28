#ifndef __VEC3_HPP__
#define __VEC3_HPP__

#include <cmath>

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

    // Generic vec3 operations
    friend vec3 operator-(vec3 u);
    friend vec3 operator+(vec3 u, vec3 v);
    friend vec3 operator-(vec3 u, vec3 v);
    friend vec3 operator*(vec3 u, vec3 v);
    friend vec3 operator*(float t, vec3 u);
    friend vec3 operator*(vec3 u, float t);
    friend vec3 operator/(vec3 u, float t);
    friend vec3& operator+=(vec3& u, vec3 v);
    friend vec3& operator-=(vec3& u, vec3 v);
    friend vec3& operator*=(vec3& u, vec3 v);
    friend vec3& operator*=(vec3& u, float t);
    friend vec3& operator/=(vec3& u, float t);

    // Norm
    float len2() { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
    float len()  { return std::sqrt(len2()); }
    static vec3 normalise(vec3 u) { return u / u.len(); }

    // vec3 operations
    static float dot(vec3 u, vec3 v) {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    }
    static vec3 cross(vec3 u, vec3 v) {
        return vec3(
            u[1]*v[2] - u[2]*v[1],
            u[2]*v[0] - u[0]*v[2],
            u[0]*v[1] - u[1]*v[0]
        );
    }
};

// Generic vec3 operations implementation
inline vec3 operator-(vec3 u) {
    return vec3(-u[0], -u[1], -u[2]);
}
inline vec3 operator+(vec3 u, vec3 v) {
    return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}
inline vec3 operator-(vec3 u, vec3 v) {
    return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}
inline vec3 operator*(vec3 u, vec3 v) {
    return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}
inline vec3 operator*(float t, vec3 u) {
    return vec3(t * u[0], t * u[1], t * u[2]);
}
inline vec3 operator*(vec3 u, float t) {
    return vec3(t * u[0], t * u[1], t * u[2]);
}
inline vec3 operator/(vec3 u, float t) {
    return vec3(u[0] / t, u[1] / t, u[2] / t);
}
inline vec3& operator+=(vec3& u, vec3 v) {
    u[0] += v[0]; u[1] += v[1]; u[2] += v[2];
    return u;
}
inline vec3& operator-=(vec3& u, vec3 v) {
    u[0] -= v[0]; u[1] -= v[1]; u[2] -= v[2];
    return u;
}
inline vec3& operator*=(vec3& u, vec3 v) {
    u[0] *= v[0]; u[1] *= v[1]; u[2] *= v[2];
    return u;
}
inline vec3& operator*=(vec3& u, float t) {
    u[0] *= t; u[1] *= t; u[2] *= t;
    return u;
}
inline vec3& operator/=(vec3& u, float t) {
    u[0] /= t; u[1] /= t; u[2] /= t;
    return u;
}

#endif