class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n && (s[i]=='+' || s[i] == '-')){
            i++;
        }

        bool flag = false;

        while(i<n && isdigit(s[i])){
            i++;
            flag=true;
        }

        if(i<n && s[i]=='.'){
            i++;
            while(i<n && isdigit(s[i])){
                i++;
                flag=true;
            }
        }

        if(flag && i<n && (s[i]=='e'||s[i]=='E')){
            i++;
            flag=false;

            if(i<n && (s[i]=='+'||s[i]=='-')){
                i++;
            }

            while(i<n && isdigit(s[i])){
                i++;
                flag=true;
            }
        }

        while(i<n && s[i]==' '){
            i++;
        }

        return flag && i==n;
    }
};
