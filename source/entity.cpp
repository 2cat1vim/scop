#include "../header/entity.hpp"

Entity::Entity(std::fstream* obj) :
_vertex(0),
_nVertex(0) {
    if (!ObjParser::parseVertex(obj, *this)) {
        throw EntityCreationException();
    }
    system("clear");
    std::cout << "[scop]: Obj file is parsed successfully" << std::endl;
    std::cout << "[scop]: Entity created linked to the Obj" << std::endl;
}
Entity::~Entity() {
}
std::vector<float> Entity::getVertex() const {
    return (this->_vertex);
}
std::vector<unsigned int> Entity::getFace() const {
    return (this->_face);
}
std::size_t Entity::getVertexSize() const {
    return (this->_nVertex);
}
std::size_t Entity::getFaceSize() const {
    return (this->_nFace);
}
void Entity::setAll(std::vector<float> v, std::vector<unsigned int> f) {
    this->_vertex = v;
    this->_face = f;
    this->_nVertex = v.size();
    this->_nFace = f.size();
}
