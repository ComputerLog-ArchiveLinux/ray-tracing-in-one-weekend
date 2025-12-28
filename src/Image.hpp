#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <vec3.hpp>

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

class Image {
public:
    int width;
    int height;
    std::vector<vec3> buffer;

public:
    // Constructor
    Image() : width(0), height(0), buffer(std::vector<vec3>()) {}
    Image(int _width, int _height) :
    width(_width), height(_height),
    buffer(std::vector<vec3>(width*height)) {}

    // Member access
    vec3& operator[](int index) { return buffer[index]; }

    // Resize
    void resize(int _width, int _height) {
        width = _width; height = _height;
        buffer = std::vector<vec3>(width*height);
    }

    // Export to PPM
    bool export_ppm(std::string filepath) {
        // Open file
        FILE* f = fopen(filepath.c_str(), "w");
        if (f == nullptr) {
            fprintf(stderr, "Unable to open for writing file ./%s\n", filepath.c_str());
            return false;
        }

        // Write signature
        fprintf(f, "P6\n");
        fprintf(f, "%d %d\n", width, height);
        fprintf(f, "255\n");

        // Write image data
        for (int i = 0; i < buffer.size(); i++) {
            fprintf(f, "%c%c%c",
                uint8_t(255.0f * buffer[i][0]),
                uint8_t(255.0f * buffer[i][1]),
                uint8_t(255.0f * buffer[i][2])
            );
        }

        // Close file
        fclose(f);

        // Log
        printf("Generated PPM image at ./%s\n", filepath.c_str());

        return true;
    }
};

#endif