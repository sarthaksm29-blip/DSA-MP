#include "BFS.h"
#include <queue>

void BFS(string start) {

    queue<string> q;
    map<string,bool> visited;

    q.push(start);
    visited[start] = true;

    cout << "\nNearby Locations:\n";

    while(!q.empty()) {

        string node = q.front();
        q.pop();

        cout << node << endl;

        for(auto neighbour : graph[node]) {

            if(!visited[neighbour.first]) {

                visited[neighbour.first] = true;
                q.push(neighbour.first);
            }
        }
    }
}