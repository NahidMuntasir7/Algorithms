// [3, 4, 5, 1, 2] 
// has been rotated 3 times

// **answer will be the position of the minimum........

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
      
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }
        if (arr[low] <= arr[mid]) {  // if left part is sorted
            if (arr[low] < ans) { 
                index = low;    // keep the minimum
                ans = arr[low];
            }
            low = mid + 1; // Eliminate left half
        }
        else {   // if right part is sorted
            if (arr[mid] < ans) {
                index = mid;    // keep the minimum
                ans = arr[mid];
            }
            high = mid - 1;  // Eliminate right half
        }
    }
    return index;
}
