//
//  render.cpp
//  Chapter02
//
//  Created by Kolomnikov Pavel on 10.04.2021.
//
#include <string>

#include "render.hpp"
#include "shader.hpp"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

GLuint positionBufferObject;
GLuint shaderProgram;
GLuint vao;

// triangle
const float vertexPositions[] = {
    -0.75f, -0.75f, 0.0f, 1.0f,
     0.75f, -0.75f, 0.0f, 1.0f,
     0.75f,  0.75f, 0.0f, 1.0f,
    
//    -0.1f, -0.1f, 0.0f, 1.0f,
//     0.1f, -0.1f, 0.0f, 1.0f,
//     0.0f,  0.1f, 0.0f, 1.0f,
//
//    -0.3f, -0.1f, 0.0f, 1.0f,
//    -0.1f, -0.1f, 0.0f, 1.0f,
//    -0.2f,  0.1f, 0.0f, 1.0f,
};

// INIT PROGRAMM
void initializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void initializeShaders()
{
    std::vector<GLuint> shaders;
    
    shaders.push_back(loadShaderFromFile(GL_FRAGMENT_SHADER, "FragPosition.frag"));
    shaders.push_back(loadShaderFromFile(GL_VERTEX_SHADER, "FragPosition.vert"));
    
    shaderProgram = createProgram(shaders);
    
    std::for_each(shaders.begin(), shaders.end(), glDeleteShader);
}

void init()
{
    initializeVertexBuffer();
    initializeShaders();
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

// LOOP
void display()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT );
    
    glUseProgram(shaderProgram);
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0 , 0);
        
    glDrawArrays(GL_TRIANGLES, 0, 9);
    
    glDisableVertexAttribArray(0);
    glUseProgram(0);
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
