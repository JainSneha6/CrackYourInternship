class Solution {
private:
    void merge(vector <int>& ans, vector<pair<int,int>>& pairs, int low, int mid ,int high){
        vector <pair<int,int>> temp(high-low+1);
        int left=low;
        int right=mid+1;
        int k=0;
        
        while(left<=mid && right<=high){
            if(pairs[left].first<=pairs[right].first){
                temp[k++]=pairs[right++];
            }
            else{
                ans[pairs[left].second]+=high-right+1;
                temp[k++]=pairs[left++];
            }
        }
        while(left<=mid){
            temp[k++]=pairs[left++];
        }
        while(right<=high){
            temp[k++]=pairs[right++];
        }
        for(int i=low;i<=high;i++){
            pairs[i]=temp[i-low];
        }
    }
    void mergeSort(vector <int>& ans, vector<pair<int,int>>& pairs, int low, int high){
        if(low>=high){
            return;
        }
        int mid = low+(high-low)/2;
        mergeSort(ans,pairs,low,mid);
        mergeSort(ans,pairs,mid+1,high);
        merge(ans,pairs,low,mid,high);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++){
            pairs.push_back({nums[i],i});
        }
        vector <int> ans(nums.size(),0);
        mergeSort(ans,pairs,0,nums.size()-1);
        return ans;
    }
};
