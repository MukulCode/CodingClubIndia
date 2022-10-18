#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int Depth[N];

void depth(int vertex, int par = -1)
{
    for (auto child : adj[vertex])
    {
        if (child == par)
            continue;
        Depth[child] = Depth[vertex] + 1;
        depth(child, vertex);
    }
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    depth(1); // run dfs using any root

    // Find max depth and node of that depth
    int max_depth = -1;
    int max_node;
    for (int i = 1; i <= N; ++i)
    {
        if (Depth[i] > max_depth)
        {
            max_depth = Depth[i];
            max_node = i;
        }
        Depth[i] = 0; // reset for 2nd dfs
    }

    // Dfs from deepset node
    depth(max_node);

    for (int i = 1; i <= N; ++i)
    {
        if (Depth[i] > max_depth)
        {
            max_depth = Depth[i];
        }
    }
    // max depth is the diameter of the tree
    cout << max_depth << endl;
}