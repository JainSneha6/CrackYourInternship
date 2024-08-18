class Disjoint{
    vector <int> parent, rank;
    public:
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
    
    void UnionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{it[0],i}});
            }
        }
        
        Disjoint ds(V);
        
        sort(edges.begin(),edges.end());
        
        int mst = 0;
        
        for(auto edge:edges){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if(ds.findParent(u)!=ds.findParent(v)){
                mst+=wt;
                ds.UnionByRank(u,v);
            }
        }
        return mst;
    }
};
