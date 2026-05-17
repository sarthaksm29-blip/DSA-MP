#include "Dijkstra.h"
#include <queue>

void dijkstra(string source) {

    map<string,int> dist;

    for(auto x : graph)
        dist[x.first] = 1e9;

    priority_queue<pair<int,string>,
                   vector<pair<int,string>>,
                   greater<pair<int,string>>> pq;

    dist[source] = 0;

    pq.push({0, source});

    while(!pq.empty()) {

        int d = pq.top().first;
        string node = pq.top().second;

        pq.pop();

        for(auto neighbour : graph[node]) {

            string next = neighbour.first;
            int weight = neighbour.second;

            if(dist[next] > d + weight) {

                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "\nShortest Distances From " << source << endl;

    for(auto x : dist)
        cout << x.first << " -> " << x.second << " km" << endl;
}