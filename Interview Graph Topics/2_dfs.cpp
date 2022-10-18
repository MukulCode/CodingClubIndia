#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // stores the graph
    map<int, list<int>> grp;
    // stores whether a node has been visited
    map<int, bool> visited;

    void addEdge(int v1, int v2);
    void DFS(int vertex);
};

void Graph::addEdge(int v1, int v2)
{
    grp[v1].push_back(v2);
    grp[v2].push_back(v1);
}

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";
    for (auto child : grp[vertex])
    {
        if (!visited[child])
            DFS(child);
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(1);
    return 0;
}