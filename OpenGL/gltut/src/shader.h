//
//  shader.hpp
//  Chapter02
//
//  Created by Kolomnikov Pavel on 20.05.2021.
//

#ifndef shader_h
#define shader_h
#include <string>
#include <vector>

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint createShader(GLenum eShaderType, const std::string &strShaderFile);
GLuint createProgram(const std::vector<GLuint> &shaderList);
GLuint loadShaderFromFile(GLenum eShaderType, const std::string &strShaderFilename);

#endif /* shader_h */