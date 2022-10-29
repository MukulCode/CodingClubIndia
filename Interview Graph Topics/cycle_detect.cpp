#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N, false);

bool isCycle(int vertex, int parent)
{
    bool Flag = false;
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        if (visited[child] && child == parent)
            continue;
        if (visited[child])
            return true;

        Flag |= isCycle(child, vertex);
    }
    return Flag;
}

int main()
{
    int v, e;
    bool ans = false;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= v; i++)
    {
        if (isCycle(i, 0))
        {
            ans = true;
            break;
        }
    }
    cout << ans << endl;
}