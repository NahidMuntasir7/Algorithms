// Time Complexity: Best Case O(n) Average Case O(n2) Worst Case O(n2)
// Space Complexity O(1)

void insert(int a[], int n){  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j >= 0 && temp <= a[j]){    
            a[j + 1] = a[j];     
            j = j - 1;    
        }    
        a[j + 1] = temp;    
    }  
}  
