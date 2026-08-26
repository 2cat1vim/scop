#include "../header/objParser.hpp"
#include <sstream>
# define VERTEX "v"
# define FACE "f"
# define SKIP_HEADER 2

bool ObjParser::parseVertex(std::fstream* obj, Entity& entity) {
    std::vector<float> queue_vertex;
    std::vector<unsigned int> queue_face;
    std::string line, queue, fqueue;
    char queue_type = 0;
    while (std::getline(*obj, line)) {
        if (line[0] == 'v') {
            queue = line.substr(SKIP_HEADER, line.size());
            queue.push_back(' ');
            queue_type = 'v';
        }
        else if (line[0] == 'f') {
            queue = line.substr(SKIP_HEADER, line.size());
            queue.push_back(' ');
            queue_type = 'f';
        }
        if (queue_type == 'v') {
            fqueue.clear();
            for (std::string::iterator it = queue.begin(); it != queue.end(); ++it) {
                if ((isdigit(*it) || *it == '.' || *it == '-')) {
                    fqueue.push_back(*it);
                }
                else {
                    std::stringstream ss(fqueue);
                    float val = 0.0f;
                    ss >> val;
                    queue_vertex.push_back(val);
                    fqueue.clear();
                }
            }
        }
        else if (queue_type == 'f') {
            fqueue.clear();
            for (std::string::iterator it = queue.begin(); it != queue.end(); ++it) {
                if (isdigit(*it)) {
                    fqueue.push_back(*it);
                }
                else {
                    std::stringstream ss(fqueue);
                    int val = 0;
                    ss >> val;
                    queue_face.push_back(val);
                    fqueue.clear();
                }
            }   
        }
        queue.clear();
    }
    obj->close();
    delete obj;
    if (queue_vertex.empty() || queue_face.empty()) {
        return (false);
    }
    entity.setAll(queue_vertex, queue_face);
    return (true);
}

int ObjParser::selectObj(std::vector<std::fstream*>& fileVector) {
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
            std::fstream* pNewFile = new std::fstream(path.c_str());
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
    if (std::cin.eof()) {
        std::cerr << "\nEOF:\n " << " CTRL-D Exit" << std::endl;
        return (-1); 
    }
    int inputAsInt = atoi(input.c_str());
    int vectorSize = fileVector.end() - fileVector.begin();
    if (vectorSize < inputAsInt || inputAsInt <= 0) {
        std::cerr << "ERROR:\n " << inputAsInt <<
            " : index doesn't exist" << std::endl;
        return (-1);
    }
    return (inputAsInt);
}

void ObjParser::fcloseAll(std::vector<std::fstream*>& list, int index) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (static_cast<int>(i) != index && list[i] != NULL) {
            list[i]->close();
            delete list[i];
        }
    }
}