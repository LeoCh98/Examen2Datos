//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_FILEMANAGER_H
#define EXAMEN2DATOS_FILEMANAGER_H
#include "Connection.h"
#include <fstream>
#include <vector>

class FileManager {
private:
    string filePath;
public:
    FileManager();
    const string &getFilePath() const;
    void setFilePath(const string &filePath);
    vector<Connection> loadConnections(const string &filename);
    Connection loadConnection(ifstream &csvInfo);
};


#endif //EXAMEN2DATOS_FILEMANAGER_H
