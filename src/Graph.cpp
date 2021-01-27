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
    cout << "VERTEX DISTANCE FROM SOURCE\n";
    for (int i = 0; i < adjList.size(); i++)
        if(!adjList[i].empty())
            cout <<nameChar(src) <<"->"<< nameChar(i) << "\t\t" << dist[i] << endl;
}

void Graph::primMST() {
    vector<bool> visited(adjList.size(),false);

    vector<int> connection(adjList.size(),1);

    vector<int> value(adjList.size(), INF);

    priority_queue<Pair, vector<Pair>, greater<Pair>> que;

    que.push(make_pair(0, 1));  //push the weight required to insert the source node =0 and the node itself(i.e 1)
    value[1]=0;                 //minimum weight for source is 0
    while (!que.empty()) {
        int node = que.top().second;  //get the node
        visited[node] = true;         //as it is visited now change its value to true
        que.pop();
        for (auto neighbor : adjList[node]) {   //we check for all its neighbors
            int weight = neighbor.second;       //get their weight
            int vertex = neighbor.first;         //get their index

            if (!visited[vertex] && value[vertex] > weight) {   //if the node is not visited and if its weight along this edge is less than the
                value[vertex] = weight;                         //previous edge associated with it, then only we consider it
                connection[vertex] = node;
                que.push(make_pair(value[vertex], vertex));     //we update the values and then push it in the queue to examine its neighbors
            }
        }
    }
    for (int i = 0; i < adjList.size(); i++)
        if (!adjList[i].empty())
            cout << nameChar(i-1) << "->" << nameChar(i) << "\t\t" << connection[i] << endl;
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
    }
}