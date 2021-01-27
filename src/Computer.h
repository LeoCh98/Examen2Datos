//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_COMPUTER_H
#define EXAMEN2DATOS_COMPUTER_H
#include <iostream>
using namespace std;
class Computer {
private:
    string name;
public:
    Computer(const string &name);
    Computer();
    const string &getName() const;
    void setName(const string &name);
    const int getNameInt();//Convert name string to int for arrays...
};


#endif //EXAMEN2DATOS_COMPUTER_H
