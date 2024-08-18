class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector <vector<int>> adj(N);
	    vector <int> indegree(N,0);
	    
	    for(int i=0;i<P;i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        indegree[prerequisites[i].first]++;
	    }
	    
	    queue <int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return count==N?1:0;
	}
};
