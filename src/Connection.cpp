//
// Created by leoch on 26/01/2021.
//

#include "Connection.h"

Connection::Connection(const Computer &comOne, const Computer &comTwo, int concrete, int gypsum, int floor,
                       int additional) : comOne(comOne), comTwo(comTwo), concrete(concrete), gypsum(gypsum),
                                         floor(floor), additional(additional) {

}

Connection::Connection() = default;

const Computer &Connection::getComOne() const {
    return comOne;
}

void Connection::setComOne(const Computer &comOne) {
    Connection::comOne = comOne;
}

const Computer &Connection::getComTwo() const {
    return comTwo;
}

void Connection::setComTwo(const Computer &comTwo) {
    Connection::comTwo = comTwo;
}

int Connection::getConcrete() const {
    return concrete;
}

void Connection::setConcrete(int concrete) {
    Connection::concrete = concrete;
}

int Connection::getGypsum() const {
    return gypsum;
}

void Connection::setGypsum(int gypsum) {
    Connection::gypsum = gypsum;
}

int Connection::getFloor() const {
    return floor;
}

void Connection::setFloor(int floor) {
    Connection::floor = floor;
}

int Connection::getAdditional() const {
    return additional;
}

void Connection::setAdditional(int additional) {
    Connection::additional = additional;
}

int Connection::makeConnection() {
    return (concrete*2.5 + gypsum*1.5 + floor*2 + additional*0.5);
}

string Connection::toString() {
    stringstream output;
    output << comOne.getName() <<","<< comTwo.getName() <<","<< concrete <<","<< gypsum <<","<< floor <<","<< additional <<","<< makeConnection() << endl;
    return output.str();
}
