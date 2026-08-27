#include "../header/module.hpp"

# define WIDTH 800
# define HEIGHT 600
# define OPENGL_VERSION 3

Module::Module() {
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    this->_window = glfwCreateWindow(WIDTH, HEIGHT, "scop - 42", NULL, NULL);
    if (!this->_window) {
        throw GlfwWindowFailed();
    }
    glfwMakeContextCurrent(this->_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw GladLoadFailed();
    }
    glViewport(0, 0, WIDTH, HEIGHT);
    std::cout << "[scop]: Glfw init -> (hint, window, glad, viewport)" << std::endl;
}

void Module::linkVertexAttrib(unsigned int i, unsigned int n, GLenum type, size_t size) {
    glVertexAttribPointer(i, n, type, GL_FALSE, n * size, (void*)0);
    glEnableVertexAttribArray(i);
}

void Module::loadModuleFromEntity(Entity& entity) {
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);
    this->genVertexObject(GL_ARRAY_BUFFER, entity.getVertexSize(), entity.getVertex().data());
    this->linkVertexAttrib(0, 3, GL_FLOAT, sizeof(float));
    this->genVertexObject(GL_ELEMENT_ARRAY_BUFFER, entity.getFaceSize(), entity.getFace().data());
}

GLFWwindow* Module::getWindow() const {
    return (this->_window);
}

void Module::swapAndProcess() const {
    glfwSwapBuffers(this->getWindow());
    glfwPollEvents();
}

void Module::processInput() const {
    if (glfwGetKey(this->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->getWindow(), true);
    }
}

void Module::clearScreen(float r, float g, float b) const {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


Module::~Module() {
    glfwDestroyWindow(this->_window);
    glfwTerminate();
}