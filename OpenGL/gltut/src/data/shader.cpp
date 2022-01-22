//
//  shader.cpp
//  Chapter02
//
//  Created by Kolomnikov Pavel on 20.05.2021.
//

#include "shader.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define LOCAL_FILE_DIR "./src/data/"
#define GLOBAL_FILE_DIR "../src/data/"

const char *getChaderType(GLenum eShaderType)
{

    const char *strShaderType = "unknown";
    switch (eShaderType)
    {
    case GL_VERTEX_SHADER:
        strShaderType = "vertex";
        break;
    case GL_GEOMETRY_SHADER:
        strShaderType = "geometry";
        break;
    case GL_FRAGMENT_SHADER:
        strShaderType = "fragment";
        break;
    }

    return strShaderType;
}

GLuint createShader(GLenum eShaderType, const std::string &strShaderFile)
{
    GLuint shader = glCreateShader(eShaderType);
    const char *strFileData = strShaderFile.c_str();
    glShaderSource(shader, 1, &strFileData, NULL);

    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

        const char *strShaderType = getChaderType(eShaderType);

        fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
        delete[] strInfoLog;
    }

    return shader;
}

GLuint createProgram(const std::vector<GLuint> &shaderList)
{
    GLuint program = glCreateProgram();

    for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
        glAttachShader(program, shaderList[iLoop]);

    glLinkProgram(program);

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
        glDetachShader(program, shaderList[iLoop]);

    return program;
}

std::string findFileOrThrow(const std::string &strBasename)
{
    std::string strFilename = LOCAL_FILE_DIR + strBasename;
    std::ifstream testFile(strFilename.c_str());
    if (testFile.is_open())
        return strFilename;

    strFilename = GLOBAL_FILE_DIR + strBasename;
    testFile.open(strFilename.c_str());
    if (testFile.is_open())
        return strFilename;

    throw std::runtime_error("Could not find the file in " + strFilename);
}

GLuint loadShaderFromFile(GLenum eShaderType, const std::string &strShaderFilename)
{
    std::string strFilename = findFileOrThrow(strShaderFilename);
    std::ifstream shaderFile(strFilename.c_str());
    std::stringstream shaderData;
    shaderData << shaderFile.rdbuf();
    shaderFile.close();

    try
    {
        return createShader(eShaderType, shaderData.str());
    }
    catch (std::exception &e)
    {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
}