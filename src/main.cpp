//
// Created by leoch on 26/01/2021.
//
#include "FileManager.h"
#include "Graph.h"
int main(){
    vector<Edge> vec;
    FileManager  fm;
    vec = fm.loadConnections( "DataBase.csv");
    cout<<"Just reading csv...\n";
    for (int i=0; i < vec.size(); i++){
        cout<<vec[i].toString();
    }
    cout<<endl;

    Graph g1(vec);
    cout<<"Graph print\n";
    g1.print();
    cout<<endl;

    cout<<"Short path test (Dijkstra) \n";
    g1.shortesPath(1);
    cout<<endl;

    cout<<"PrimMST:\n";
    g1.primMST();
    cout<<endl;

    /*cout<<"Kruskal: (still in process)\n";
    g1.kruskalMST();
    cout<<endl;*/

    return -1;
}