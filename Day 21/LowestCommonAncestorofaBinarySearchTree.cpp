class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map <string,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]+=1;
        }

        string ans = "";

        for(auto it:m){
            if(it.second==1){
                --k;
            }
            if(k==0){
                ans=it.first;
            }
        }
        return ans;
    }
};
