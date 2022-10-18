#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int inf = 1e9;
vector<pair<int, int>> adj[];

void dijk(int source)
{
    vector<int> dist(N, inf);
    set<pair<int, int>> st;
    vector<int> vis(N, 0);

    st.insert({0, source});
    dist[source] = 0;
    while (!st.empty())
    {
        auto it = *st.begin();
        int v = it.second;
        int v_dist = it.first;
    }
}