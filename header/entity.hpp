#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <print>
#include <vector>
#include <dirent.h>
#include <string>
#include <cstdio>
#include <stdlib.h>

class Entity {
    private:
        std::FILE* _obj;
        std::vector<float> _vertex;
        std::size_t _nVertex;
    public:
        Entity(std::FILE* obj);
        ~Entity();

        std::FILE* getObj() const;
        std::vector<float> getVertex() const;
        std::size_t getVertexSize() const;
        void setVertex(std::vector<float> vertex);
        void setVertexSize(std::size_t n);
};

#endif