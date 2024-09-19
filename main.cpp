#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

const std::string VertexSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec2 vertex;\n"
    "\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(vertex, 0.0, 1.0);\n"
    "}\n";

// Fragment shader source code
const std::string FragmentSource = 
    "#version 330 core\n"
    "out vec4 color;\n"
    "\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0, 0.2, 0.3, 1.0);\n"
    "}\n";

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return 1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", nullptr,nullptr);
    if (!window)
    {
        std::cerr << "Failed tocreate a window!" << std::endl;
        glfwTerminate();
        return 1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!(glewInit() == GLEW_OK))
    {
        std::cerr << "FAiled to intiaialize GLEW!" << std::endl;
        glfwTerminate();
        return 1;
    }

    float vertices[] = {
         0.0f, 0.5f,
         0.5f, -0.5f,
        -0.5f, -0.5f
    };

    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *) 0);

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexSource = VertexSource.c_str();
    glShaderSource(vertex, 1, &vertexSource, nullptr);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentSource = FragmentSource.c_str();
    glShaderSource(fragment, 1, &fragmentSource, nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    // Check for compilation errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Failed\n" << infoLog << std::endl;
    }

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Failed\n" << infoLog << std::endl;
    }

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    // Check for linking errors
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Shader Program Linking Failed\n" << infoLog << std::endl;
    }

    glUseProgram(program);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}