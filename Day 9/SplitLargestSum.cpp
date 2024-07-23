class Solution {
private:
    int solve(vector<int>& nums, int mid){
        int count=1,totalsum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+totalsum>mid){
                count++;
                totalsum=nums[i];
            }
            else{
                totalsum+=nums[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid)<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
