    // left
    int n = arr.size();
    k = k % n; // Handle cases where k > n

    reverse(arr.begin(), arr.begin() + k); // Reverse the first k elements
    reverse(arr.begin() + k, arr.end());   // Reverse the rest
    reverse(arr.begin(), arr.end());       // Reverse the entire array

    rotateLeft(arr, k);

    // STL
    rotate(arr.begin(), arr.begin() + k, arr.end())


      
    // right
    int n = arr.size();
    k = k % n; // Handle cases where k > n

    reverse(arr.begin(), arr.end() - k);   // Reverse the first n-k elements
    reverse(arr.end() - k, arr.end());     // Reverse the last k elements
    reverse(arr.begin(), arr.end());       // Reverse the entire array

    rotateRight(arr, k);

    // STL
    rotate(arr.begin(), arr.end() - k, arr.end())


    // rotate(begin, middle, end);
    The elements between begin and middle are moved to the end of the range, 
    and the elements between middle and end are moved to the beginning.




    


    
    
