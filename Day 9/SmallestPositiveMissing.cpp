class Solution
{
    private:
        int segregate(int arr[], int n) {
            int j = 0;
            for(int i=0;i<n;i++) {
                if(arr[i]<=0)
                    swap(arr[i],arr[j++]);
            }
            return j;
        }
        
        int smallest(int arr2[], int n) {
            for(int i=0;i<n;i++) {
                int x = abs(arr2[i]);
                if(x-1<n && arr2[x-1]>0)
                    arr2[x-1]*=-1;
            }
            for(int i=0;i<n;i++) {
                if(arr2[i]>0)
                    return i+1;
            }
            return n+1;
        }
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int seg = segregate(arr,n);
        return smallest(arr+seg,n-seg);
    } 
};
