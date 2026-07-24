class Solution {
public:
    void dfs(vector<int>& vis, int i, vector<vector<int>>& adj){
        vis[i] = 1;
        for(auto n: adj[i]){
            if(vis[n]==0){
                dfs(vis, n, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>>adj(V);
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(V, 0);
        int count = 0;
        for(int i = 0; i<V;i++){
            if(vis[i]==0){
                dfs(vis, i, adj);
                count++;
            }
        }

        return count;
    }
};