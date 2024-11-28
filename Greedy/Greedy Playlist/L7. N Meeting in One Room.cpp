// There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting 
// while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. 
// Print the order in which these meetings will be performed.

// Example:
// Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
// Output: 1 2 4 5


#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of meetings
void maxMeetings(int start[], int end[], int N) {
    vector<pair<int, pair<int, int>>> meetings;

    // Create a vector of {end time, {start time, index}}
    for (int i = 0; i < N; i++) {
        meetings.push_back({end[i], {start[i], i + 1}});
    }

    // Sort meetings by end time (primary) and index (secondary)
    sort(meetings.begin(), meetings.end());

    vector<int> selectedMeetings;
    int lastEndTime = 0;

    // Iterate over the meetings to find the maximum set
    for (auto &meeting : meetings) {
        if (meeting.second.first > lastEndTime) {
            selectedMeetings.push_back(meeting.second.second);
            lastEndTime = meeting.first;
        }
    }

    // Print the order of selected meetings
    for (int i : selectedMeetings) {
        cout << i << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int N = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};

    maxMeetings(start, end, N);

    return 0;
}


