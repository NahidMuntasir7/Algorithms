// a sorted array given... 
// [1, 1, 2, 2, 3, 3, (4), 5, 5, 6, 6]
// only 1 number will appear once... and all other number will be twice
// findout that number

// [1, 1, 2, 2, 3, 3, (4), 5, 5, 6, 6]
//  0  1  2  3  4  5   6   7  8  9  10
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); 

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    // dummy return statement:
    return -1;
}

