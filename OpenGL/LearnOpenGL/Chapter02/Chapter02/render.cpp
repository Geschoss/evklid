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

GLuint vertexBufferObject;
GLuint shaderProgram;
GLuint vao;

// triangle

const float vertexData[] = {
     0.0f,    0.5f, 0.0f, 1.0f,
     0.5f, -0.366f, 0.0f, 1.0f,
    -0.5f, -0.366f, 0.0f, 1.0f,
     1.0f,    0.0f, 0.0f, 1.0f,
     0.0f,    1.0f, 0.0f, 1.0f,
     0.0f,    0.0f, 1.0f, 1.0f,
};

// INIT PROGRAMM
void initializeShaders()
{
    std::vector<GLuint> shaders;
    
    shaders.push_back(loadShaderFromFile(GL_FRAGMENT_SHADER, "VertexColors.frag"));
    shaders.push_back(loadShaderFromFile(GL_VERTEX_SHADER, "VertexColors.vert"));
    
    shaderProgram = createProgram(shaders);
    
    std::for_each(shaders.begin(), shaders.end(), glDeleteShader);
}

void initializeVertexBuffer()
{
    glGenBuffers(1, &vertexBufferObject);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)48);
        
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glUseProgram(0);
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
