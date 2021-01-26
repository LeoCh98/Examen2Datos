//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_COMPUTER_H
#define EXAMEN2DATOS_COMPUTER_H
#include <iostream>

class Computer {
private:
    std::string name;
public:
    Computer(const std::string &name);
    Computer();
    const std::string &getName() const;
    void setName(const std::string &name);
};


#endif //EXAMEN2DATOS_COMPUTER_H
