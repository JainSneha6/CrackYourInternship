class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        for(char ch: s){
            if(!st.empty() && st.top().first==ch){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            else{
                st.push({ch,1});
            }
        }
        string res;
        while(!st.empty()){
            res.append(st.top().second,st.top().first);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
