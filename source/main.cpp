#include "../header/entity.hpp"

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

int selectObj(std::vector<FILE*> fileVector) {
    std::string pathDir = "obj_list/";
    struct dirent* next;
    DIR* dir = opendir(pathDir.c_str());
    if (!dir) {
        std::cerr << "ERROR:\n " << pathDir << " : is missing" << std::endl;
        return (-1);
    }
    size_t i = 0;
    while ((next = readdir(dir))) {
        std::string file = next->d_name;
        std::size_t fileSize = file.size();
        if (file.size() < 5)
            continue;
        std::string last = file.substr(fileSize - 4, fileSize);
        if (last == ".obj") {
            std::string path = pathDir;
            path.append(file);
            FILE* pNewFile = fopen(path.c_str(), "r");
            if (!pNewFile) {
                std::cerr << "ERROR:\n " << file << " : fopen failed" << std::endl;
                return (-1);
            }
            std::cout << "File[" << i + 1 << "]: " << file << std::endl;
            fileVector.push_back(pNewFile);
        }
        i++;
    }
    closedir(dir);
    std::string input;
    std::cout << "Select a file to load (ex: 1): ";
    std::cin >> input;
    int inputAsInt = atoi(input.c_str());
    int vectorSize = fileVector.end() - fileVector.begin();
    if (vectorSize < inputAsInt || inputAsInt <= 0) {
        std::cerr << "ERROR:\n " << inputAsInt <<
            " : index doesn't exist" << std::endl;
        return (-1);
    }
    return (inputAsInt);
}

int main(int ac, char* av[]) {
    (void)av;
    if (ac > 1) {
        std::cerr << "error : scop expect no argument" << std::endl;
        return (1);
    }
    printHdr();
    std::vector<FILE*> fileVector;
    int objIndex = selectObj(fileVector);
    if (objIndex == -1) {
        return (1);
    }
}