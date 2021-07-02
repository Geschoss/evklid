//
//  render.cpp
//  Chapter02
//
//  Created by Kolomnikov Pavel on 10.04.2021.
//
#include <string>

#include "render.hpp"
#include "shader.hpp"
#include "date.hpp"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

GLuint positionBufferObject;
GLuint shaderProgram;
GLuint vao;

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

unsigned long startTime;

// triangle
const float vertexPositions[] = {
    0.25f, 0.25f, 0.0f, 1.0f,
    0.25f, -0.25f, 0.0f, 1.0f,
    -0.25f, -0.25f, 0.0f, 1.0f,
};

// INIT PROGRAMM
void initializeShaders()
{
    std::vector<GLuint> shaders;
    
    shaders.push_back(loadShaderFromFile(GL_VERTEX_SHADER, "standart.vert"));
    shaders.push_back(loadShaderFromFile(GL_FRAGMENT_SHADER, "standart.frag"));
    
    shaderProgram = createProgram(shaders);
    
    std::for_each(shaders.begin(), shaders.end(), glDeleteShader);
}

void initializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STREAM_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void init()
{
    startTime = fgSystemTime();
    initializeVertexBuffer();
    initializeShaders();
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

// LOOP
void computePositionOffsets(float &fXOffset, float &fYOffset)
{
    const float fLoopDuration = 1.0f;
    const float fScale = 3.14159f * 2.0f / fLoopDuration;

    float fElapsedTime = fgElapsedTime(startTime) / 1000.0f;

    float fCurrTimeThroughLoop = fmodf(fElapsedTime, fLoopDuration);

    fXOffset = cosf(fCurrTimeThroughLoop * fScale) * 0.5f;
    fYOffset = sinf(fCurrTimeThroughLoop * fScale) * 0.5f;
}

void adjustVertexData(float fXOffset, float fYOffset)
{
    std::vector<float> fNewData(ARRAY_COUNT(vertexPositions));
    memcpy(&fNewData[0], vertexPositions, sizeof(vertexPositions));
    
    for(int iVertex = 0; iVertex < ARRAY_COUNT(vertexPositions); iVertex += 4)
    {
        fNewData[iVertex] += fXOffset;
        fNewData[iVertex + 1] += fYOffset;
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexPositions), &fNewData[0]);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void display()
{
    float fXOffset = 0.0f, fYOffset = 0.0f;
    computePositionOffsets(fXOffset, fYOffset);
    adjustVertexData(fXOffset, fYOffset);
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glUseProgram(0);

}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
