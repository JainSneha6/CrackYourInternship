class Solution {
public:
    string decodeString(string s) {
        stack <int> st;
        stack <string> res;
        string curr="";
        int k=0;
        for(char ch:s){
            if(isdigit(ch)){
                k = k*10 +(ch-'0');
            }
            else if(ch=='['){
                st.push(k);
                res.push(curr);
                curr="";
                k=0;
            }
            else if(ch==']'){
                int count = st.top();
                st.pop();
                string str = res.top();
                res.pop();

                for(int i=0;i<count;i++){
                    str+=curr;
                }
                curr=str;
            }
            else{
                curr+=ch;
            }
        }
        return curr;
    }
};
