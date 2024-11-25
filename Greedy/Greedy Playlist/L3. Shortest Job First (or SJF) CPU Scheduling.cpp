// Problem Statement: Given a list of job durations representing the time it takes to complete each job. Implement the Shortest Job First algorithm to find the average waiting time for these jobs.

// Example 1:
// Input:jobs = [3, 1, 4, 2, 5]
                
// Output: 4
// Explanation: 
// The first job that will be executed is of duration 1 and the waiting time for it will be 0.
// After the first job, the next shortest job with a duration of 2 will be executed with a waiting time of 1.
// Following the completion of the first two jobs, the next shortest job with a duration of 3 will be executed with a waiting time of 3 (1 + 2).
// Then, the job with a duration of 4 will be executed with a waiting time of 6 (1 + 2 + 3).
// Finally, the job with the longest duration of 5 will be executed with a waiting time of 10 (1 + 2 + 3 + 4).
// Hence, the average waiting time is calculated as (0 + 1 + 3 + 6 + 10) / 5 = 20 / 5 = 4.

// 1 2 3 4 5 (sorted)
// 0 1 3 6 10 (wait for each)

                            
#include<bits/stdc++.h>
using namespace std;

float shortestJobFirst(vector<int> jobs) {
  
    sort(jobs.begin(), jobs.end()); 

    float waitTime = 0; 
    int totalTime = 0; 
    int n = jobs.size(); 

    for(int i = 0; i < n; ++i) 
        waitTime += totalTime; 
        totalTime += jobs[i]; 
    }
    return waitTime / n; 
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: " << ans << endl;;
}
                            
                        


