//
// Created by leoch on 26/01/2021.
//

#include "Graph.h"

Graph::Graph( vector<Edge> &edges) {
    int N = edges.size();
    adjList.resize(N);
    for (auto &edge: edges){
        int src = edge.getComOne().getNameInt();
        int dest = edge.getComTwo().getNameInt();
        int weight = edge.makeConnection();

        // insert at the end
        adjList[src].push_back(make_pair(dest, weight));
    }
}

Graph::~Graph() {
    /*
     **Just in case when using ptr**
     for (int i = 0; i < adjList.size(); i++)
        delete[] adjList[i];
    delete[] adjList;*/
}

void Graph::shortesPath(int src) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<int> dist(adjList.size(), INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x:adjList[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "VERTEX DISTANCE FROM SOURCE '"<<nameChar(src)<<"' \n";
    for (int i = 0; i < adjList.size(); i++)
        if(!adjList[i].empty())
            cout <<nameChar(src) <<"->"<< nameChar(i) << "\t\t" << dist[i] << endl;
}

int Graph::find_set(int i,vector<int> parent) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i],parent);
}

void Graph::kruskalMST() {
    vector<vector<Pair>> T(adjList.size());
    vector<int> parent;
    parent.resize(adjList.size());
    int i, uRep=0, vRep=0;
    sort(adjList.begin(), adjList.end());  // increasing weight
    for (i = 0; i < adjList.size()-6; i++) {
        uRep = find_set(adjList[i].data()->first, parent);
        vRep = find_set(adjList[i].data()->second, parent);
        if (uRep != vRep) {
            T[i].push_back( make_pair(uRep, vRep) );  // add to tree
            parent[uRep] = parent[vRep];
        }
    }
    for (int i = 0; i < T.size(); i++){
        if(!T[i].empty()) {
            for (Pair v :T[i]) {
                cout << "(" << nameChar(i) << ", " << nameChar(v.first) << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
}

void Graph::primMST() {
    int src = 0;
    int V = adjList.size();

    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        vector<pair<int, int> >::iterator i;
        for (i = adjList[u].begin(); i != adjList[u].end(); ++i) {

            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight) {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V - 6; ++i)
        cout << nameChar(parent[i]) << " -> " << nameChar(i) << endl;
}

void Graph::print() {
    for (int i = 0; i < adjList.size(); i++){
        if(!adjList[i].empty()) {
            for (Pair v :adjList[i]) {
                cout << "(" << nameChar(i) << ", " << nameChar(v.first) << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
}

char Graph::nameChar(int i) {
    switch(i){
        case 0:
            return 'A';
            break;
        case 1:
            return 'B';
            break;
        case 2:
            return 'C';
            break;
        case 3:
            return 'D';
            break;
        case 4:
            return 'E';
            break;
        case 5:
            return 'F';
            break;
        case 6:
            return 'G';
            break;
        case 7:
            return 'H';
            break;
        case 8:
            return 'I';
            break;
        default:
            return 'X';
            break;
    }
}
