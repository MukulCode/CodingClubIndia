
// int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col)
// {
//     queue<pair<int,int>> q;
//     q.push({i,j});

//     int cnt=1;

//     while(!q.empty())
//     {
//         int x_front = q.front().first;
//         int y_front = q.front().second;
//         q.pop();

//         for(int k=0;k<8;i++)
//         {
//             int ni = x_front+dx[k];
//             int nj = y_front+dy[k];
//             if(ni>=0 && nj>=0 && ni<row && nj<col && visited[ni][nj]==0 && grid[ni][nj]==1 )
//             {
//                 q.push({ni,nj});
//                 visited[ni][nj]=1;
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }