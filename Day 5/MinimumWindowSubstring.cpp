class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        vector <int> hash(256,0);
        int start=-1,minlen=INT_MAX;
        int l=0, r=0, count=0;

        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        
        while(r<n){
            if(hash[s[r]]>0){
                count++;
            }
            hash[s[r]]--;
            while(count==m){
                int len = r-l+1;
                if(len<minlen){
                    minlen=len;
                    start=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l+=1;
            }
            r+=1;
        }
        return start==-1?"":s.substr(start,minlen);
    }
};
