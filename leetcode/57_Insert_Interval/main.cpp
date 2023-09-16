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
        if (intervals.size() == 0) {
            return vector<vector<int>>(1, newInterval);
        }

        bool beginFound = false, endFound = false;
        int beginIdx = 0;
        int endIdx = 0;
        for (size_t i = 0; i < intervals.size(); i++) {
            vector<int>& v = intervals[i];

            if (!beginFound) {
                if (newInterval[0] < v[0]) {
                    beginIdx = i*2; 
                    beginFound = true;
                } else if (newInterval[0] <= v[1]) {
                    beginIdx = i*2 + 1;
                    beginFound = true;
                }
            }
            if (!endFound) {
                if (newInterval[1] < v[0]) {
                    endIdx = i*2;
                    endFound = true;
                } else if (newInterval[1] <= v[1]) {
                    endIdx = i*2 + 1;
                    endFound = true;
                }
            }
        }

        if (!beginFound) {
            beginIdx = intervals.size()*2;
        }
        if (!endFound) {
            endIdx = intervals.size()*2;
        }

        vector<int> intervalToInsert(2, 0);
        intervalToInsert[0] = (beginIdx % 2 == 0) ? newInterval[0] : intervals[static_cast<int>(beginIdx / 2)][0];
        intervalToInsert[1] = (endIdx % 2 == 0) ? newInterval[1] : intervals[static_cast<int>(endIdx / 2)][1];

        vector<int> indiciesToRemove;
        for (int i = beginIdx; i <= endIdx; i++) {
            if (i % 2 == 1) {
                indiciesToRemove.push_back(static_cast<int>(i / 2));
            }
        }

        vector<vector<int>> newIntervals = intervals;
        for (auto it = indiciesToRemove.rbegin(); it != indiciesToRemove.rend(); it++) {
            newIntervals.erase(newIntervals.begin() + *it);
        }
        newIntervals.insert(newIntervals.begin() + static_cast<int>(beginIdx / 2), intervalToInsert);

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
    vector<int> newInterval = {2, 7};

    printVectorOfIntervals(intervals);
    vector<vector<int>> insertedInterval = s.insert(intervals, newInterval);
    printVectorOfIntervals(insertedInterval);

    return 0;
}

