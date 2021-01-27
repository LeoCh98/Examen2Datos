//
// Created by leoch on 26/01/2021.
//

#include "Edge.h"

Edge::Edge(const Computer &comOne, const Computer &comTwo, int concrete, int gypsum, int floor,
           int additional) : comOne(comOne), comTwo(comTwo), concrete(concrete), gypsum(gypsum),
                                         floor(floor), additional(additional) {

}

Edge::Edge() = default;

Computer &Edge::getComOne() {
    return comOne;
}

void Edge::setComOne(const Computer &comOne) {
    Edge::comOne = comOne;
}

Computer &Edge::getComTwo() {
    return comTwo;
}

void Edge::setComTwo(const Computer &comTwo) {
    Edge::comTwo = comTwo;
}

int Edge::getConcrete() const {
    return concrete;
}

void Edge::setConcrete(int concrete) {
    Edge::concrete = concrete;
}

int Edge::getGypsum() const {
    return gypsum;
}

void Edge::setGypsum(int gypsum) {
    Edge::gypsum = gypsum;
}

int Edge::getFloor() const {
    return floor;
}

void Edge::setFloor(int floor) {
    Edge::floor = floor;
}

int Edge::getAdditional() const {
    return additional;
}

void Edge::setAdditional(int additional) {
    Edge::additional = additional;
}

int Edge::makeConnection() {
    return (concrete*2.5 + gypsum*1.5 + floor*2 + additional*0.5);
}

string Edge::toString() {
    stringstream output;
    output << comOne.getName() <<","<< comTwo.getName() <<","<< makeConnection() << endl;
    return output.str();
}
