#include "../header/entity.hpp"
#include "../header/module.hpp"

# define RENDER_LOOP_UNTIL_WINDOW_CLOSE \
    !glfwWindowShouldClose(mdl.getWindow())
# define CLEAR_SCREEN_RGB \
    0.1f, 0.1f, 0.1f

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

    /*       USER OBJ FILE SELECTION       */
    std::vector<std::fstream*> fileVector;
    int objIndex = -1;
    try {
        objIndex = ObjParser::selectObj(fileVector);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        ObjParser::fcloseAll(fileVector, -1);
        return (1);
    }
    ObjParser::fcloseAll(fileVector, objIndex - 1);
    /***************************************/

    /*      OPENGL & GLFW RENDER LOOP      */
    try {
        Entity entity(fileVector[objIndex - 1]);
        Module mdl;
        while (RENDER_LOOP_UNTIL_WINDOW_CLOSE) {
            mdl.clearScreen(CLEAR_SCREEN_RGB);
            mdl.processInput();
            mdl.genVertexObject(entity.getVertexSize(), entity.getVertex());
            mdl.swapAndProcess();
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    /****************************************/
}