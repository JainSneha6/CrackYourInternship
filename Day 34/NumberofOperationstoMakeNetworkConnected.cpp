class Disjoint{
    public:
    vector <int> parent, rank;
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(ulp_u<ulp_v){
            parent[ulp_v]=ulp_u;
        }
        else if(ulp_u>ulp_v){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int extra = 0;
        for(auto connection:connections){
            int u = connection[0];
            int v = connection[1];

            if(ds.findParent(u)==ds.findParent(v)){
                extra++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                count++;
            }
        }
        int ans = count-1;
        if(extra>=ans){
            return ans;
        }
        return -1;
    }
};
