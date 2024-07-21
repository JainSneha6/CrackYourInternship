class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            columnNumber--;
            int num = columnNumber%26;
            ans=char(num+'A')+ans;
            columnNumber/=26;
        }
        return ans;
    }
};
