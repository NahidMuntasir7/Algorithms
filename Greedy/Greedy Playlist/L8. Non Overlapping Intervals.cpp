// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.


class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {  // static is imp
        return a[1] < b[1]; // Sort by end time
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;

        // Use the static comparison function
        sort(intervals.begin(), intervals.end(), cmp);

        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i][0]) {
                res++;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return res;        
    }
};

// using a lambda instead

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i][0]) {
                res++;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return res;        
    }
};
