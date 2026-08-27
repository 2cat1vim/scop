#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <print>
#include <vector>
#include <dirent.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <exception>
#include <sstream>
#include "../header/objParser.hpp"

class Entity {
    private:
        std::vector<float> _vertex;
        std::vector<unsigned int> _face;
        std::size_t _nVertex;
        std::size_t _nFace;
    public:
        Entity(std::fstream* obj);
        ~Entity();

        std::vector<float> getVertex() const;
        std::vector<unsigned int> getFace() const;
        std::size_t getVertexSize() const;
        std::size_t getFaceSize() const;
        void setAll(std::vector<float> v, std::vector<unsigned int> f);

        class EntityCreationException : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR: \n Failed to create Entity";
                }
        };
};

#endif