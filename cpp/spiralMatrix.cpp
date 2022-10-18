#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    int firstRow = 0,firstCol = 0, lastRow = m-1,lastCol = n-1;
    while(ans.size()<(m*n)) {
        for(int j = firstCol; j <= lastCol; j++) {
            ans.push_back(matrix[firstRow][j]);
        }
        if(ans.size()==(m*n)) break;
        firstRow++;
        for(int k = firstRow; k <= lastRow; k++) {
            ans.push_back(matrix[k][lastCol]);
        }
        lastCol--;
        if(ans.size()==(m*n)) break;
        for(int l = lastCol; l >= firstCol; l--) {
            ans.push_back(matrix[lastRow][l]);
        }
        lastRow--;
        if(ans.size()==(m*n)) break;
        for(int m = lastRow; m >= firstRow; m--) {
            ans.push_back(matrix[m][firstCol]);
        }
        firstCol++;
        if(ans.size()==(m*n)) break;
    }
    return ans;
}
void solve() {
    
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin>>matrix[i][j];
    }
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < n*m; i++) cout<<ans[i]<<" ";
    cout<<endl;
    
	return 0;
}