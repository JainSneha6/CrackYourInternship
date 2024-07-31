class Solution {
private: 
    vector <int> findnse(vector<int>& arr){
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector <int> findpse(vector<int>& arr){
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector <int> nse = findnse(arr);
        vector <int> pse = findpse(arr);
        int n = arr.size();
        long long sum = 0;
        long long mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            sum = (sum + (long long)arr[i]*(i-pse[i])*(nse[i]-i))%mod;
        }
        return sum;
    }
};
