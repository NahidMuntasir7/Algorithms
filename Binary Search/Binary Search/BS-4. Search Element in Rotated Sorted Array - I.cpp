// rotated sorted array 
// [1, 2, 3, 4, 5] -> [4, 5, 1, 2, 3]

// the array will be having ** unique eliments **

int low = 0, high = n - 1;

while(low <= high){
    mid = (low + high) / 2;
    if(arr[mid] == target) return mid;
    // left sorted
    if(arr[low] <= arr[mid]){
        if(arr[low] <= target and target <= arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    //right sorted
    else{
        if(arr[mid] <= target and target <= arr[high]) low = mid + 1;
        else high = mid - 1;
    }
}
