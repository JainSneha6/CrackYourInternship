class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> pairs;
	    for(int i=0;i<nums.size();i++){
	        pairs.push_back({nums[i],i});
	    }
	    int count=0;
	    sort(pairs.begin(),pairs.end());
	    for(int i=0;i<nums.size();i++){
	        if(i==pairs[i].second){
	            continue;
	        }
	        else{
	            count++;
	            swap(pairs[i],pairs[pairs[i].second]);
	            i--;
	        }
	    }
	    return count;
	}
};
