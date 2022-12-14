#include "Data.hpp"

// ---------Constructor and destructor ------------

Data::Data(float nbr) : _nbr(nbr) {
    std::cout << "A new Data structure is created" << std::endl;
}

Data::Data(const Data& instance) {
    *this = instance;
}

Data::~Data() {
    std::cout << "A Data structure is destructed" << std::endl;
}

// --------- Fonctions ------------

float Data::getNbr() const {
    return this->_nbr;
}

void Data::setNbr(float f) {
    this->_nbr = f;
}


// --------- Operator overload ------------

Data &Data::operator=(const Data &instance) {
    std::cout << "A Data is copied" << std::endl;
    this->_nbr = instance._nbr;
    return *this;
}
