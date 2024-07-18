string smallestWindow (string s, string p)
    {
        int l=0,r=0;
        vector <int> hash(256,0);
        int n=s.length(),m=p.length();
        for(int i=0;i<m;i++){
            hash[p[i]]+=1;
        }
        int count=0;
        int minlen=INT_MAX;
        int start=-1;
        while(r<n){
            if(hash[s[r]]>0){
                count+=1;
            }
            hash[s[r]]--;
            while(count==m){
                int len=r-l+1;
                if(len<minlen){
                    minlen=len;
                    start=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count-=1;
                }
                l++;
            }
            r++;
        }
        return start==-1?"-1":s.substr(start,minlen);
