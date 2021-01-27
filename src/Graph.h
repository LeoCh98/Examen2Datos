//
// Created by leoch on 26/01/2021.
//

#ifndef EXAMEN2DATOS_GRAPH_H
#define EXAMEN2DATOS_GRAPH_H
#include <vector>
#include "Edge.h"
#include <queue>
#define INF 0X3f3f3f3f

typedef pair<int,int> Pair;
class Graph {
private:
    vector<vector<Pair>> adjList;
public:
    Graph(vector<Edge> &edges);
    void shortesPath(int src);
    void primMST();
    void print();
    char nameChar(int i); //just to see letters instead of numbers
};




#endif //EXAMEN2DATOS_GRAPH_H
