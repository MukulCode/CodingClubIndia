/*
PROBLEM STATEMENT:
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Idea: As there can be multiple sources and multiple destinations so use BFS
and also cost is unit and is not changing
*/

//direction array
vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
bool isValid(int i,int j,int m,int n){
    if(i==m || j==n || i<0 ||j<0) return false;
    return true;
}
void solve(vector<vector<int>> &matrix,vector<vector<int>> &ans){
    queue<pair<int,int>> q;
    int m=matrix.size(), n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //as 0 distance from itself so use them as source
            if(matrix[i][j]==0){
                q.push({i,j}); //pushing the coordinates
                ans[i][j]=0; //updating distance as 0
            }
        }
    }
    //BFS
    while(!q.empty()){
        pair<int,int> curr=q.front();
        q.pop();
        //iterate for 4 directions
        for(auto it:dir){
            int a=curr.first+it[0];
            int b=curr.second+it[1];
            //checking out of bound and unvisited condition
            if(isValid(a,b,m,n) && ans[a][b]==-1){
                q.push({a,b});
                ans[a][b]=ans[curr.first][curr.second]+1;//updating with level+1
            }
        }
    }

}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> ans(m,vector<int>(n,-1));
    solve(matrix,ans);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}