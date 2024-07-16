class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int sum=0,count=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum - k;
            count+=m[rem];
            m[sum]+=1;
        }
        return count;
    }
};
