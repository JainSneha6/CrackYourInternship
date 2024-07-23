#include <bits/stdc++.h> 
bool sortArr(int n, vector<int> &arr){
    int start=-1,end=-1;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            start=i;
            break;
        }
    }
    if(start==-1){
        return true;
    }
    
    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            end=i;
            break;
        }
    }

    reverse(arr.begin()+start,arr.begin()+end+1);

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
