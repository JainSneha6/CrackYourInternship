class Solution{
private:
    bool isSafe(int node, vector <int> &color, bool graph[101][101], int m, int n){
        for(int i=0;i<n;i++){
            if(node!=i && graph[i][node]==1 && color[i]==m){
                return false;
            }
        }
        return true;
    }
    
    bool solve(int node, vector <int> &color, bool graph[101][101], int m, int n){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,graph,i,n)){
                color[node]=i;
                if(solve(node+1,color,graph,m,n)){
                    return true;
                }
                color[node]=0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
       vector <int> color(n,0);
       if(solve(0,color,graph,m,n)){
           return true;
       }
       return false;
    }
};
