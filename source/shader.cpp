#include "../header/shader.hpp"

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    const char* vertexShaderSource = this->retrieveShader(vertexPath);
    const char* fragmentShaderSource = this->retrieveShader(fragmentPath); 
    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glAttachShader(_id, vertexShader);
    glAttachShader(_id, fragmentShader);
    glLinkProgram(_id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

const char* Shader::retrieveShader(const char* path) {
    std::fstream file(path);
    if (!file.is_open()) {
        throw StreamException();
    }

    std::stringstream ss;
    ss << file.rdbuf();
    return (ss.str().c_str());
}

void Shader::use() {
    glUseProgram(_id);
}