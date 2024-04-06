// [1, 2, 3, 4, 5, 6, 7, (8), 5, 1] peak = 8
// [1, (2), 1, 3, 5, (6), 4] peak = 2, 6

// return any one peak 

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array

    // Edge cases
    if (n == 1) return 0; // only element
    if (arr[0] > arr[1]) return 0; // first element is a peak
    if (arr[n - 1] > arr[n - 2]) return n - 1; // last element is a peak

    int low = 1, high = n - 2; // 1st last element eliminated ^
    while (low <= high) {
        int mid = (low + high) / 2;

        // if arr[mid] is the peak
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;

        if (arr[mid] > arr[mid - 1]) low = mid + 1;  // if we are in the left
        
        else high = mid - 1; // if we are in the right.. or, arr[mid] is a common point
    }
  
    return -1;
}

