//
// Created by leoch on 26/01/2021.
//

#include "FileManager.h"

FileManager::FileManager() {
    filePath = "..\\..\\Data\\";
}

const string &FileManager::getFilePath() const {
    return filePath;
}

void FileManager::setFilePath(const string &filePath) {
    FileManager::filePath = filePath;
}

vector<Connection> FileManager::loadConnections(const string &filename) {
    ifstream csv;
    vector<Connection> connections;
    try {
        csv.open( filePath + filename, ios::in);
        if(csv.good()) { //+
            while (!csv.eof() && csv.good()) {
                Connection _connection = loadConnection(csv);
                connections.push_back(_connection);
            }
        }
        csv.close();
    }
    catch (std::ifstream::failure a) {
        exit(1);
    }
    return connections;
}

Connection FileManager::loadConnection(ifstream &csvInfo) {
    Connection newCon;
    string name1, name2;
    string con,gyp,floor,add;

    getline(csvInfo, name1, ',');
    getline(csvInfo, name2, ',');
    getline(csvInfo, con, ',');
    getline(csvInfo, gyp, ',');
    getline(csvInfo, floor, ',');
    getline(csvInfo, add, '\n');

    Computer c1(name1);Computer c2(name2);
    newCon.setComOne(c1);
    newCon.setComTwo(c2);
    newCon.setConcrete(stoi(con));
    newCon.setGypsum(stoi(gyp));
    newCon.setFloor(stoi(floor));
    newCon.setAdditional(stoi(add));

    return newCon;
}
