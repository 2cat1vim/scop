#ifndef MODULE_HPP
#define MODULE_HPP
#include "entity.hpp"
#include "../external/glad/glad.h"
#include <GLFW/glfw3.h>

class Module {
    private:
        GLFWwindow* _window;
    public:
        Module();
        ~Module();

        GLFWwindow* getWindow() const;
        void swapAndProcess() const;
        void processInput() const;
        void clearScreen(float r, float g, float b) const;

        template <typename T> unsigned int genVertexObject(size_t size, T* data);

        class GlfwWindowFailed : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR:\n GLFW Window failed";
                }
        };
        class GladLoadFailed : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR: \n GLAD Load failed";
                }
        };
};

#endif