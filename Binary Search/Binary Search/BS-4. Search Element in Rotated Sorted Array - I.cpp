// rotated sorted array (unique) 
// [1, 2, 3, 4, 5] -> [4, 5, 1, 2, 3]

// the array will be having ** unique eliments **


int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == k) return mid; //if mid points the target

        //if left part is sorted
        if (arr[low] <= arr[mid]) {
            if(arr[low] <= k and k <= arr[mid]) high = mid - 1; //element exists
            else low = mid + 1; //element does not exist
        }
        //if right part is sorted
        else{ 
            if(arr[mid] <= k and k <= arr[high]) low = mid + 1;
            else  high = mid - 1;
        }
    }
    return -1;
}
