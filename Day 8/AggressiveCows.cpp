private:
    int canWePlace(int n, int k, vector<int>& stalls, int mid){
        int count=1;
        int lastStall=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-lastStall>=mid){
                count++;
                lastStall=stalls[i];
            }
            if(count>=k){
                return true;
            }
        }
        return false;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=1,high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canWePlace(n,k,stalls,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
