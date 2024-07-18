class Solution {
public:
    int calculate(string s) {
        stack <int> st;
        int curr=0;
        char op='+';

        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                curr=curr*10+(s[i]-'0');
            }
            if(!isdigit(s[i]) && !isspace(s[i])||i==s.size()-1){
                if(op=='+'){
                    st.push(curr);
                }
                else if(op=='-'){
                    st.push(-curr);
                }
                else if(op=='*'){
                    int val = st.top();
                    st.pop();
                    st.push(val*curr);
                }
                else if(op=='/'){
                    int val = st.top();
                    st.pop();
                    st.push(val/curr);
                }
                op=s[i];
                curr=0;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
