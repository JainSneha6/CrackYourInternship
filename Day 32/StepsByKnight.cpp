class Solution 
{
    private:
    bool isValid(int i, int j, int N, vector<vector<int>>&vis){
        return (i>=0 && i<N && j>=0 && j<N && !vis[i][j]);
    }
    
    public:
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    
	    int desx = TargetPos[0]-1;
	    int desy = TargetPos[1]-1;
	    
	    int i = KnightPos[0]-1;
	    int j = KnightPos[1]-1;
	    
	    queue<pair<int,pair<int,int>>> q;
	    
	    q.push({0,{i,j}});
	    vis[i][j]=1;
	    
	    int dir[8][2]={{-1,-2},{1,-2},{2,-1},{2,1},{-1,2},{1,2},{-2,-1},{-2,1}};
	    
	    while(!q.empty()){
	        int dist = q.front().first;
	        int x = q.front().second.first;
	        int y = q.front().second.second;
	        q.pop();
	        
	        if(x==desx && y==desy){
	            return dist;
	        }
	        
	        for(int k=0;k<8;k++){
	                
	           int nx = x+dir[k][0];
	           int ny = y+dir[k][1];
	                
	           if(isValid(nx,ny,N,vis)){
	               q.push({dist+1,{nx,ny}});
	               vis[nx][ny]=1;
	           }
	       }
	    }
	    return -1;
	}
};
