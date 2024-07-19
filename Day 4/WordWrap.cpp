int solve(vector<int>nums, int k, int ind, vector<int>& dp){
        int n = nums.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MAX;
        int sum=0;
        for(int i=ind;i<n;i++){
            sum+=nums[i];
            if(k>=sum && i==n-1){
                ans=min(ans,solve(nums,k,i+1,dp));
            }
            else if(k>=sum){
                int x = k-sum;
                x*=x;
                ans=min(ans,x+solve(nums,k,i+1,dp));
            }
            sum++;
        }
        return dp[ind]=ans;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector <int> dp(n,-1);
        return solve(nums,k,0,dp);
    } 
