#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool visited[N];

void DFS(int vertex)
{
    cout << vertex << endl;
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        if (visited[child])
            continue;
        DFS(child);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(0);
}