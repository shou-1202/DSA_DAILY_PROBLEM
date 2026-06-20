class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size() == 0){
            return n-1;
        }
        int ans = 0;
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        for(int i = 1;i<restrictions.size();i++){
            int distance = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1]+distance);
        }
        int m = restrictions.size();
        for(int i = m-2;i>=0;i--){
            int distance = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1]+distance);
        }

        int maxheight = 0;
        for(int i = 1;i<m;i++){
            int id1 = restrictions[i-1][0], h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];

            int height = (h1+h2+id2-id1)/2;
            maxheight = max(maxheight, height);
        }
        int height = restrictions[m-1][1] + (n-restrictions[m-1][0]);
        return max(maxheight, height);
    }
};