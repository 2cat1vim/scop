#include "../header/entity.hpp"
#include "../external/glad/glad.h"
#include <GLFW/glfw3.h>

void printHdr() {
    std::cout << "  \n   $$$$$$$\\  $$$$$$$\\  $$$$$$\\   $$$$$$\\ " << std::endl;  
    std::cout << "  $$  _____|$$  _____|$$  __$$\\ $$  __$$\\ " << std::endl; 
    std::cout << "  \\$$$$$$\\  $$ /      $$ /  $$ |$$ /  $$ | " << std::endl;
    std::cout << "   \\____$$\\ $$ |      $$ |  $$ |$$ |  $$ | " << std::endl;
    std::cout << "  $$$$$$$  |\\$$$$$$$\\ \\$$$$$$  |$$$$$$$  | " << std::endl;
    std::cout << "  \\_______/  \\_______| \\______/ $$  ____/ " << std::endl; 
    std::cout << "                                $$ | " << std::endl;      
    std::cout << "                                $$ | " << std::endl;      
    std::cout << "                                \\__| " << std::endl;      
}

int main(int ac, char* av[]) {
    (void)av;
    if (ac > 1) {
        std::cerr << "error : scop expect no argument" << std::endl;
        return (1);
    }
    printHdr();
    std::vector<std::fstream*> fileVector;
    int objIndex = ObjParser::selectObj(fileVector);
    if (objIndex == -1) {
        ObjParser::fcloseAll(fileVector, -1);
        return (1);
    }
    int index = objIndex - 1;
    ObjParser::fcloseAll(fileVector, index);
    Entity entity(fileVector[index]);
}