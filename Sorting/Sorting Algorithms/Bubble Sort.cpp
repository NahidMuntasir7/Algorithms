// normal

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if( arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
}

// optimized

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}
