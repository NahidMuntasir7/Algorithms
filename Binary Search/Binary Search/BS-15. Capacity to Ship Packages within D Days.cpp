// Problem statement
// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. 
// The loaded weights must not exceed the maximum weight capacity of the ship.

// Find out the least-weight capacity so that you can ship all the packages within 'd' days.
// Sample Input 1:
// 8 5
// 5 4 5 2 3 4 5 6
// Sample Output 1:
// 9


class Solution {
public:

    int findDays(vector<int>& weights, int capacity){
        int Day = 1, load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                Day += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return Day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = (low + high) / 2;
            int noOfDays = findDays(weights,mid);
            if(noOfDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
