#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

extern map<string, vector<pair<string,int>>> graph;

void addEdge(string u, string v, int w);
void showGraph();

#endif