public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack <int> st;
        for(char ch:S){
            if(isdigit(ch)){
                st.push(ch-'0');
            }
            else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                switch(ch){
                    case '+':
                       st.push(val1+val2);
                       break;
                    case '-':
                       st.push(val1-val2);
                       break;
                    case '*':
                       st.push(val1*val2);
                       break;
                    case '/':
                       st.push(val1/val2);
                       break;
                }
            }
        }
        return st.top();
    }
