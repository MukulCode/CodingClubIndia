#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> graph[N];
bool vis[N];

void DFS(int vertex)
{
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        if (!vis[child])
            DFS(child);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}

// https://leetcode.com/problems/flood-fill/submissions/
// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
