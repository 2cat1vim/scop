#include "../header/entity.hpp"

Entity::Entity(FILE* obj) :
_vertex(0),
_nVertex(0) {
}
Entity::~Entity() {
}

std::FILE* Entity::getObj() const {
    return (this->_obj);
}
std::vector<float> Entity::getVertex() const {
    return (this->_vertex);
}
std::size_t Entity::getVertexSize() const {
    return (this->_nVertex);
}
void Entity::setVertex(std::vector<float> vertex) {
    this->_vertex = vertex;
}
void Entity::setVertexSize(std::size_t n) {
    this->_nVertex = n;
}