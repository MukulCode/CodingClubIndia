#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
int height[N];
int depth[N];

void dfs(int vertex, int parent = 0)
{
    for (int child : adj[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int vertex;
    cin >> vertex;
    for (int i = 0; i < vertex - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= vertex; i++)
    {
        cout << depth[i] << " " << height[i] << endl;
    }
    return 0;
}