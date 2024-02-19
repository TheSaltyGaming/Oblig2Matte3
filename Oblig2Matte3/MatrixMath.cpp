#include "MatrixMath.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Eigen/Dense>

#include "Vertex.h"


void MatrixMath::MatrixCalculations()
{
    Eigen::MatrixXf A(8, 3);
    Eigen::VectorXf b(8);

    A << 16.0, -4.0, 1.0,
          9.0, -3.0, 1.0,
          1.0,  -1.0, 1.0,
          9.0,  3.0, 1.0,
          16.0,  4.0, 1.0,
          36.0,  6.0, 1.0,
          49.0,  7.0, 1.0,
          64.0,  8.0, 1.0;
    b << -2.0, 1.0, 5.0, 5.0, 2.0, 2.0, 4.0, 6.0;

    
    Eigen::VectorXf solution = A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);

    
    std::cout << "The least squares solution [a, b, c] for the quadratic fit is:\n" << solution << std::endl;
    ax = solution[0];
    bx = solution[1];
    cx = solution[2];
    
}

void MatrixMath::MatrixInterpolation()
{
    Eigen::MatrixXf A(4, 4);
    Eigen::VectorXf b(4);

    A <<27.0, 9.0, 3.0, 1.0,
          125.0, 25.0, 5.0, 1.0,
          343.0,  49.0, 7.0, 1.0,
          512.0,  64.0, 8.0, 1.0;
    b << 5.0, 2.0, 4.0, 6.0;
    

    
    Eigen::VectorXf solution = A.inverse() * b;

    
    std::cout << "The interpolation coefficients  [a, b, c, d]  is:\n" << solution << std::endl;
     ax2 = solution[0];
     bx2 = solution[1];
     cx2 = solution[2];
     dx2 = solution[3];
}

std::vector<Vertex> MatrixMath::WriteDataPoints()
{
    std::vector<Vertex> mVertices;
    for (int i = 0; i < num_points; ++i)
    {
        long double x = a + i * h; // Beregn x-verdien
        
        long double y = f(x); // Beregn y-verdien
        

        Vertex vertex;
        vertex.x = x;
        vertex.y = y;
        vertex.z = 0.0f;
        
        vertex.r = 1.0f;
        vertex.g = 0.0f;
        vertex.b = 0.0f;
        mVertices.push_back(vertex);
    }
    return mVertices;
}

long double MatrixMath::f(double x)
{
    return ax*x*x + bx*x + cx;
}


    
