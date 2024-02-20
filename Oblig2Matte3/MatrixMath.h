#pragma once
#include <iosfwd>
#include <vector>
#include <vector>
#include <glm/fwd.hpp>

#include "Vertex.h"

struct mVertex
{
    float x, y, z;
};

class MatrixMath
{
public:
    std::vector<glm::vec3> vertexlist;
    float ax = 0.0f;
    float bx = 0.0f;
    float cx = 0.0f;

    float ax2 = 0.0f;
    float bx2 = 0.0f;
    float cx2 = 0.0f;
    float dx2 = 0.0f;
    
    glm::mat4x3 CreateMatrix(float x, float y, float z);

    void Fillvector();
    void MatrixCalculations();
    void MatrixInterpolation();
    std::vector<Vertex> WriteDataPoints();
    std::vector<Vertex> WriteDataPoints2();

private:
    long double a = -20.0; // Startpunkt
    long double b = 20.0;  // Sluttpunkt
    int num_points = 200; // Antall datapunkter
    long double h = (b-a)/num_points;

    long double f(double x);
    long double f2(double x);
};
