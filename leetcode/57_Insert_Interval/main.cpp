#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        if (intervals.size() == 0) {
            return {newInterval};
        }

        size_t i = 0;
        for (; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (newInterval[0] <= interval[1]) {
                break;
            } else {
                newIntervals.push_back(interval);
            }
        }

        for (; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            newInterval[0] = min(newInterval[0], interval[0]);
            if (newInterval[1] < interval[0]) {
                break;
            }
            newInterval[1] = max(newInterval[1], interval[1]);
        }
        newIntervals.push_back(newInterval);

        for (; i < intervals.size(); i++) {
            newIntervals.push_back(intervals[i]);
        }

        return newIntervals;
    }
};

void printVectorOfIntervals(const vector<vector<int>>& intervals) {
    cout << "{";
    for (vector<int> v : intervals) {
        cout << "{" << v[0] << ", " << v[1] << "}, ";
    }
    cout << "}" << endl;
}

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 5}};
    // vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {6, 8};

    printVectorOfIntervals(intervals);
    vector<vector<int>> insertedInterval = s.insert(intervals, newInterval);
    printVectorOfIntervals(insertedInterval);

    return 0;
}

