#include "renderer.h"

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cerr << "[OpenGL ERROR]: " << "(" << error << ")" << " " << function << " " << file << " : " << line << std::endl;
        return false;
    }

    return true;
}