//  same as previous but the array contains duplicate element
// last algo for unique element wont work here...

// [3, 1, 2, 3, 3, 3, 3] ... fails here ...

// cannot give the index of the element - not possible with previous binary search algo
// have to say the element is in the array or not

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue; //
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) high = mid - 1;  // element exists            
            else low = mid + 1; // element does not exist
            }
        //if right part is sorted:
        else { 
            if (arr[mid] <= k && k <= arr[high]) low = mid + 1; //element exists
            else  high = mid - 1; //element does not exist
            }
    }
    return false;
}
