class Solution
{
    private:
        vector <int> findnse(int arr[],int n){
            stack <int> st;
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
        vector <int> findpse(int arr[],int n){
            stack <int> st;
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
    
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> nse = findnse(arr,n);
        vector<int> pse = findpse(arr,n);
        vector <int> ans(n+1,0);
        for(int i=0;i<n;i++){
            if(nse[i]==-1){
                nse[i]=n;
            }
            int len = nse[i]-pse[i]-1;
            ans[len] = max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};
