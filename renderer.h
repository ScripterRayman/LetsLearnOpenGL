#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <iostream>

#define ASSERT(x) if (!(x)) std::cerr << "\tYOU HAVE AN ERROR .... FIX IT !!!!!!" << std::endl

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char *function, const char *file, int line);

#endif