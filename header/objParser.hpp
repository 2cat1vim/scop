#ifndef OBJPARSER_HPP
#define OBJPARSER_HPP
#include "entity.hpp"

class Entity;

class ObjParser {
    public:
        static bool parseVertex(std::fstream* obj, Entity& entity);
        static void fcloseAll(std::vector<std::fstream*>& list, int index);
        static int selectObj(std::vector<std::fstream*>& fileVector);

        class EOFException : public std::exception {
            public:
                const char* what() const throw() {
                    return "\nEOF:\n CTRL-D Exit";
                }
        };
        class IndexException : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR:\n Index doesn't exist";
                }
        };
        class StreamException : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR:\n fstream failed";
                }
        };
        class DirException : public std::exception {
            public:
                const char* what() const throw() {
                    return "ERROR:\n obj_list/ : is missing";
                }
        };
};

#endif