void countingSort(int arr[], int exp, int n) {
    vector<int> output(n);
    int count[10] = {0};
   
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
   
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
   
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) { 
    int maxNum = *max_element(arr, arr + n);
    
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp, n);
    }
}
