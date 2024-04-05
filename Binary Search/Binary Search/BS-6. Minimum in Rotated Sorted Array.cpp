// Minimum in Rotated Sorted Array (unique)

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
  
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid]) { // if left part is sorted
            ans = min(ans, arr[low]); // keep the minimum
            low = mid + 1; // Eliminate left half:
        }
        else {  //if right part is sorted
            ans = min(ans, arr[mid]); // keep the minimum
            high = mid - 1; // Eliminate right half
        }
    }
    return ans;
}


// more optimized

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
  
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high]) { // search space is already sorted.. then arr[low] will always be the minimum in that search space
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid]) {   // if left part is sorted
            ans = min(ans, arr[low]); // keep the minimum
            low = mid + 1; // Eliminate left half
        }
        else { //if right part is sorted
            ans = min(ans, arr[mid]); // keep the minimum
            high = mid - 1; // Eliminate right half:
        }
    }
    return ans;
}

