//
// Created by leoch on 26/01/2021.
//
#include "FileManager.h"

int main(){
    vector<Connection> vec;
    FileManager  fm;
    vec = fm.loadConnections( "DataBase.csv");

    for (int i=0; i < vec.size(); i++){
        cout<<vec[i].toString();
    }

    return -1;
}