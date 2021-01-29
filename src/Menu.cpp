//
// Created by leoch on 28/01/2021.
//

#include "Menu.h"

Menu::Menu() = default;

void Menu::start() {
    vector<Edge> vec;
    FileManager  fm;
    vec = fm.loadConnections( "DataBase.csv");
    Graph _graph(vec);
    string choice;
    while (true) {
        try {
            cout    <<"\n\t Welcome to Compu Mundo Hyper Mega Red\n"
                    << "1. Load Data\n"
                    << "2. Dijkstra\n"
                    << "3. Kruskal\n"
                    << "4. Prim\n"
                    << "5. Exit\n"
                    << "\t Option: ";
            cin >> choice;
            switch (atoi(choice.c_str())) {
                case 1:{
                    cout<<"\nGraph print\n";
                    _graph.print();
                    cout<<endl;
                    break;
                }
                case 2:{
                    string src;
                    cout<<"\nShort path (Dijkstra) \n";
                    cout << "A=0 B=1 C=2 D=3 E=4 F=5 G=6 H=7 I=8\n";
                    cout<<"Please enter a source: (0-8) \n";
                    cin>>src;
                    _graph.shortesPath(stoi(src));
                    cout<<endl;
                    break;
                }
                case 3:{
                    cout<<"\nPrimMST:\n";
                    _graph.primMST();
                    cout<<endl;
                    break;
                }
                case 4:{
                    cout<<"\nKruskal: (Still in process...) \n";
                    _graph.kruskalMST();
                    cout<<endl;
                    break;
                }
                case 5: {
                    cout << "Thank you!!!" << endl;
                    exit(0);
                }
                default: {
                    cout << "Invalid entry\n\n";
                    break;
                }
            }
        } catch (exception e) {
            cout << "Please enter valid input" << endl;
        }
    }
}