// lower bound  ->  arr[i] >= n | arr[i] is the smallest indexed one
// arr[] = 3, 5, 8, 15, 19, 19, 19
// let n = 8  so, lower bound = 8 
// let n = 9  so, lower bound = 15 
// let n = 19 so, lower bound = 19(1st occurence)
// let n = 20..  lower bound = last index + 1 / size of the array


// implementing lower bound

int low = 0, high = n - 1;
int ans = n; // 
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if(arr[mid] >= n){
        ans = mid; // last high before the loop breaks... after this low > high
        high = mid - 1;
    }
    else low = mid + 1;
}

