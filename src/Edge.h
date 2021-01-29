//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_EDGE_H
#define EXAMEN2DATOS_EDGE_H
#include "Computer.h"
#include <sstream>

class Edge {
private:
    Computer comOne; //Vertex 1
    Computer comTwo; //Vertex 2

    //Variables to calculate weight
    int concrete;
    int gypsum;
    int floor;
    int additional;
public:
    Edge();
    virtual ~Edge();
    Computer &getComOne() ;
    void setComOne(const Computer &comOne);
    Computer &getComTwo() ;
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


#endif //EXAMEN2DATOS_EDGE_H
