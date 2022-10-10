#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll answer = 1;
ll findMinimumHealth(int **magic, int si, int sj, int ei, int ej, int **dp) {
    if (si == ei && sj == ej)
        return 1;
    if (si > ei || sj > ej)
        return INT_MAX;
    if (dp[si][sj] > -1)
        return dp[si][sj];
    ll right = findMinimumHealth(magic, si + 1, sj, ei, ej, dp);
    ll down = findMinimumHealth(magic, si, sj + 1, ei, ej, dp);
    ll step = min(right, down) - magic[si][sj];
    dp[si][sj] = max(step, 1ll);
    return dp[si][sj];
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int r, c;
        cin >> r >> c;
        int **magic = new int *[r];
        for (int i = 0; i < r; i++)
            magic[i] = new int[c];

        int **dp = new int *[r];
        for (int i = 0; i < r; i++)
            dp[i] = new int[c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                dp[i][j] = -1;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cin >> magic[i][j];
        }
        cout << findMinimumHealth(magic, 0, 0, r - 1, c - 1, dp) << endl;
    }
    return 0;
}
// END
