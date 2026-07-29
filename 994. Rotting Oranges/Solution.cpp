class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int delRow[] = {0, -1, 0, +1};
        int delCol[] = {-1, 0, +1, 0};
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();
            for(int i = 0; i<4; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && vis[newR][newC]!=2 && grid[newR][newC]==1){
                    q.push({{newR, newC}, t+1});
                    vis[newR][newC] = 2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};