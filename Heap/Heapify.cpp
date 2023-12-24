void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2* i;
    // int left = 2*i+1    ==> when starting from zero index
    int right = 2* i + 1;
    // int right = 2*i+2   ==> when starting from zero index
    if(left < n and arr[largest] < arr[left])
        largest = left;
    if(right < n and arr[largest] < arr[right])
        largest = right;

    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
