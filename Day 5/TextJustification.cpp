class Solution {
public:
    string getLine(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words, int maxWidth){
        string s;

        for(int k=i;k<j;k++){
            s+=words[k];

            if(k==j-1){
                continue;
            }

            for(int space=1;space<=eachWordSpace;space++){
                s+=" ";
            }

            if(extraSpace>0){
                s+=" ";
                extraSpace--;
            }
        }

        while(s.length()<maxWidth){
            s+=" ";
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string> res;
        int n=words.size();
        int i=0;

        while(i<n){
            int letters=words[i].length();
            int j=i+1;
            int spaces=0;

            while(j<n && spaces+letters+words[j].length()+1<=maxWidth){
                letters+=words[j].length();
                spaces+=1;
                j++;
            }

            int rem=maxWidth-letters;

            int eachWordSpace = spaces==0?0:rem/spaces;
            int extra = spaces==0?0:rem%spaces;

            if(j==n){
                eachWordSpace = 1;
                extra = 0;
            }

            res.push_back(getLine(i,j,eachWordSpace,extra,words,maxWidth));
            i=j;
        }
        return res;
    }
};
