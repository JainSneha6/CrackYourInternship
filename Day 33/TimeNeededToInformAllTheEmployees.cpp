class Solution {
private:
    int dfs(int headID, vector<vector<int>> &adj, vector<int>& informTime){
        int maxTime = 0;
        for(auto it: adj[headID]){
            maxTime = max(maxTime,dfs(it,adj,informTime));
        }
        return maxTime + informTime[headID];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime);
    }
};
