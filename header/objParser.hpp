#ifndef OBJPARSER_HPP
#define OBJPARSER_HPP

#include <iostream>
#include <print>
#include <vector>
#include <dirent.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "entity.hpp"

class Entity;

class ObjParser {
    public:
        static bool parseVertex(std::fstream* obj, Entity& entity);
        static void fcloseAll(std::vector<std::fstream*>& list, int index);
        static int selectObj(std::vector<std::fstream*>& fileVector);
};

#endif