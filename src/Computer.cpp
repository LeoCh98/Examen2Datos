//
// Created by leoch on 26/01/2021.
//

#include "Computer.h"

Computer::Computer(const std::string &name) : name(name) {

}

Computer::Computer() {

}

const std::string &Computer::getName() const {
    return name;
}

void Computer::setName(const std::string &name) {
    Computer::name = name;
}
