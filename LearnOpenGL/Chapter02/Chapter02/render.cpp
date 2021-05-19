//
//  render.cpp
//  Chapter02
//
//  Created by Kolomnikov Pavel on 10.04.2021.
//
#include <string>

#include "render.hpp"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

const float vertexPositions[] = {
    0.75f, 0.75f, 0.0f, 1.0f,
    0.75f, -0.75f, 0.0f, 1.0f,
    -0.75f, -0.75f, 0.0f, 1.0f,
};
GLuint positionBufferObject;


const std::string strFragmentShader(
    "#version 330                                   \n"
    "out vec4 outputColor;                          \n"
    "void main()                                    \n"
    "{                                              \n"
    "   outputColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); \n"
    "}                                              \n"
);

void init()
{
    glGenBuffers(1, &positionBufferObject);
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void display()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT );
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0 , 0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
