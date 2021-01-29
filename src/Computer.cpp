//
// Created by leoch on 26/01/2021.
//

#include "Computer.h"

Computer::Computer(const string &name) : name(name) {

}

Computer::Computer() = default;

Computer::~Computer() = default;

const string &Computer::getName() const {
    return name;
}

void Computer::setName(const string &name) {
    Computer::name = name;
}

const int Computer::getNameInt() {
    //cant use switch structure with strings so...
    if(name=="A")
        return 0;
    else
        if(name=="B")
            return 1;
        else
            if(name=="C")
                return 2;
            else
                if(name=="D")
                    return 3;
                else
                    if(name=="E")
                        return 4;
                    else
                        if(name=="F")
                            return 5;
                        else
                            if(name=="G")
                                return 6;
                            else
                                if(name=="H")
                                    return 7;
                                else
                                    if(name=="I")
                                        return 8;
}


