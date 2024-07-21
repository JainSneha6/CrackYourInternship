class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) {
            return -1;
        }
        if(needle == "") {
            return 0;
        }
        int R=256;
        vector<int>right (R, -1);
        int m = needle.size();
        for(int i = 0; i < m; i++) {
            right[needle[i]] = i;
        }
        for(int i = 0; i <= haystack.size() -m; i++) {
            int step = 0;
            for(int j=m-1; j>= 0; j--) {
                if(haystack[i+j] != needle[j]) {
                    step = j - right[haystack[(i + j)]];
                    if(step<0) step = 1;
                    break;
                }
            }
            if(step == 0) {
                return i;
            }
        }
        
        return -1;
    }
        
};
