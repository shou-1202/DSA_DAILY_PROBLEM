class Solution {
public:
    void dfs(int src, vector<vector<int>>& res, vector<int>& temp, vector<vector<int>>& graph){
        int n = graph.size();
        temp.push_back(src);
        if(src == n-1){
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int neigh: graph[src]){
            dfs(neigh, res, temp, graph);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>res;
        vector<int>temp;

        dfs(0, res, temp, graph);
        return res;
    }
};