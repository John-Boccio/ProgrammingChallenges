#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <cctype>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distHeap;
        size_t i = 0;
        for (; i < min(static_cast<int>(points.size()), k); i++) {
            int dist = distToOrigin(points[i]);
            distHeap.push_back({dist, i});
        }
        make_heap(distHeap.begin(), distHeap.end());

        for (; i < points.size(); i++) {
            int dist = distToOrigin(points[i]);
            if (dist < distHeap[0].first) {
                pop_heap(distHeap.begin(), distHeap.end());
                distHeap.pop_back();
                distHeap.push_back({dist, i});
                push_heap(distHeap.begin(), distHeap.end());
            }
        }

        vector<vector<int>> kClosestPoints;
        for (auto& point : distHeap) {
            kClosestPoints.push_back(points[point.second]);
        }
        return kClosestPoints;
    }

private:
    inline int distToOrigin(const vector<int>& point2D) {
        return static_cast<int>(pow(point2D[0], 2) + pow(point2D[1], 2));
    }
};

void printVectorOf2DPoints(const vector<vector<int>>& intervals) {
    cout << "{";
    for (vector<int> v : intervals) {
        cout << "{" << v[0] << ", " << v[1] << "}, ";
    }
    cout << "}" << endl;
}

int main() {
    Solution s;

    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    printVectorOf2DPoints(points);
    cout << "K = " << k << endl;
    auto kClosestPoints = s.kClosest(points, k);
    printVectorOf2DPoints(kClosestPoints);
    
    return 0;
}

