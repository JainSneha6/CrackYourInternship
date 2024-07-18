class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string rev="";
        while(getline(ss,word,' ')){
            if(word!=""){
                if(rev!=""){
                    rev=word+' '+rev;
                }
                else{
                    rev=word;
                }
            }
        }
        return rev;
    }
};
