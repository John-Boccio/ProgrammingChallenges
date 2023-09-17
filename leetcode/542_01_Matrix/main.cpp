#include <unordered_set>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distTo0(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    distTo0[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> offsets = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            for (const pair<int, int>& offset : offsets) {
                int newRow = current.first + offset.first;
                int newCol = current.second + offset.second;
                if (isValidIdx(mat, newRow, newCol) && distTo0[newRow][newCol] == -1) {
                    distTo0[newRow][newCol] = distTo0[current.first][current.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return distTo0;
    }

private:
    inline bool isValidIdx(const vector<vector<int>>& mat, int row, int col) {
        int rows = mat.size();
        int cols = mat[0].size();
        return (row >= 0 && row < rows) && (col >= 0 && col < cols);
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    for (const vector<int>& row : mat) {
        cout << "[";
        for (const int& val : row) {
            cout << val << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int>> mat = {{0, 0, 0,}, {0, 1, 0}, {1, 1, 1}};

    printMatrix(mat);
    auto updatedMatrix = s.updateMatrix(mat);
    printMatrix(updatedMatrix);

    return 0;
}

