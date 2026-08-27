#ifndef SHADER_HPP
#define SHADER_HPP

#include "module.hpp"

class Shader {
    private:
        unsigned int _id;
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        std::string retrieveShader(const char* path);
        void use();

        class StreamException : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR:\n fstream failed";
                }
        };
};

#endif