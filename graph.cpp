#include "graph.h"

map<string, vector<pair<string,int>>> graph;

void addEdge(string u, string v, int w) {

    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}

void showGraph() {

    cout << "\nCity Map\n";

    for(auto x : graph) {

        cout << x.first << " -> ";

        for(auto y : x.second)
            cout << y.first << "(" << y.second << "km) ";

        cout << endl;
    }
}