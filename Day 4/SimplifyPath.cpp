class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        stringstream ss(path);
        string part;
        while(getline(ss,part,'/')){
            if(part=="."||part==""){
                continue;
            }
            else if(part==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(part);
            }
        }
        string cpath="";
        while(!st.empty()){
            cpath="/"+st.top()+cpath;
            st.pop();
        }
        if(cpath==""){
            cpath="/";
        }
        return cpath;
    }
};
