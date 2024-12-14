// by adding a new element in a subarray... the subarray count incereases by the length..
// 1 2 3 (4).... 4 subarray increased

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        deque<int> maxQ;    // monotonic decreasing queue - {5 , 3 , 2, 1}
        deque<int> minQ;    // monotonic increasing queue - {1, 2, 5}
        int l=0, r=0;       //sliding window parameters
        while(r<n){
            // maintain monotonicity of maxQ and minQ including rth element
            while(!maxQ.empty() && nums[r] > maxQ.back())
                maxQ.pop_back();
            while(!minQ.empty() && nums[r] < minQ.back())
                minQ.pop_back();

            // insert rth element in queues
            maxQ.push_back(nums[r]);
            minQ.push_back(nums[r]);

            // shrink left side based on given condition after including rth element
            while(maxQ.front() - minQ.front() > 2){
                // update maxQ, minQ and left boundary 
                if(nums[l] == maxQ.front())     // if lth element is max of this window
                    maxQ.pop_front();
                if(nums[l] == minQ.front())     // if lth element is min of this window
                    minQ.pop_front();
                l++;
            }
            ans += r - l + 1;                   // update ans
            r++;                                // expand right side
        }
        return ans;
    }
};
