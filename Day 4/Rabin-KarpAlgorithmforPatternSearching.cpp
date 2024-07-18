class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m > n) return -1;

        const int base = 26;
        const int prime = 101; 

        int needleHash = 0; 
        int windowHash = 0; 
        int h = 1;

        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % prime;
        }

        for (int i = 0; i < m; i++) {
            needleHash = (base * needleHash + needle[i]) % prime;
            windowHash = (base * windowHash + haystack[i]) % prime;
        }

        for (int i = 0; i <= n - m; i++) {

            if (needleHash == windowHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i; 
            }

            if (i < n - m) {
                windowHash = (base * (windowHash - haystack[i] * h) + haystack[i + m]) % prime;

                if (windowHash < 0) {
                    windowHash = (windowHash + prime);
                }
            }
        }

        return -1;
    }
};
