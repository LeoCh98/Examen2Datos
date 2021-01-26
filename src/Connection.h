//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_CONNECTION_H
#define EXAMEN2DATOS_CONNECTION_H
#include "Computer.h"
#include <sstream>
using namespace std;

class Connection {
private:
    Computer comOne;
    Computer comTwo;
    int concrete;
    int gypsum;
    int floor;
    int additional;
public:
    Connection(const Computer &comOne, const Computer &comTwo, int concrete, int gypsum, int floor, int additional);
    Connection();
    const Computer &getComOne() const;
    void setComOne(const Computer &comOne);
    const Computer &getComTwo() const;
    void setComTwo(const Computer &comTwo);
    int getConcrete() const;
    void setConcrete(int concrete);
    int getGypsum() const;
    void setGypsum(int gypsum);
    int getFloor() const;
    void setFloor(int floor);
    int getAdditional() const;
    void setAdditional(int additional);
    int makeConnection();
    string toString();
};


#endif //EXAMEN2DATOS_CONNECTION_H
