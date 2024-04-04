// first and last occurance of a given number


// first occurence = lower bound
// last  occurence = upper bound - 1

// edge cases

// first occurence and last occurence

// logic: if lb == n: the element is not present so, if not present then no first last 
// if lb present may not be equal to x

// if lb is present and equal to x.. then always, last occ = ub - 1 think..

  if(lb == n or arr[lb] != x) lb and ub not present
  else{
        first = lb;
        last = ub - 1
   }



// code: normal binary search
// first occ
int low = 0, high = n - 1;
int first = -1;
while(low <= high){
    int mid = (low + high) / 2;
    if(arr[mid] == n){
      first = mid;
      high = mid - 1; // <----
    }
    else if(arr[mid] < n) low = mid + 1;
    else hi = mid - 1;
}
// if first == -1 then not present

// last occ
int low = 0, high = n - 1;
int last = -1;
while(low <= high){
    int mid = (low + high) / 2;
    if(arr[mid] == n){
      last = mid;
      lo = mid + 1; // ---->
    }
    else if(arr[mid] < n) low = mid + 1;
    else hi = mid - 1;
}
// if last == -1 then not present

// if no first occurence then no last occurence


// sorted array given check a elements occurence

int ans = lastocc - firstocc + 1
