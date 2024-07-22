public:
    long long solve(int n, int arr[], int mid){
        long long count=1,totalpages=0;
        for(int i=0;i<n;i++){
            if(arr[i]+totalpages>mid){
                count++;
                totalpages=arr[i];
            }
            else{
                totalpages+=arr[i];
            }
        }
        return count;
    }
    long long findPages(int n, int arr[], int m) {
        if(m>n){
            return -1;
        }
        int low=*max_element(arr,arr+n);
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(solve(n,arr,mid)<=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
