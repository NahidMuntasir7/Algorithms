// lower bound as bs

 auto it = lower_bound(arr.begin(), arr.end(), target);
// Check if the value at the iterator is equal to the target
 if(it != arr.end() && *it == target) index =  it - arr.begin();
