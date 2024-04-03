//  *** when elenent is not in the array ***
//  1 2 3 (4) (6) 7
//  0 1 2  3   4  5
//  for element 5: index of -> low = 4 and high = 3 | ** then the loop breaks **


//  overflow case: mid = lo + (hi - lo) / 2


while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x) return mid;
    else if (array[mid] < x) low = mid + 1;
    else high = mid - 1;
}
