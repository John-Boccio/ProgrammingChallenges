#include <cstdint>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxToRight(prices.size(), 0);
        int currentMax = -INT_MAX;
        for (int i = prices.size() - 1; i >= 0; i--) {
            currentMax = max(prices[i], currentMax);
            maxToRight[i] = currentMax;
        }

        int profit = -INT_MAX;
        for (size_t i = 0; i < maxToRight.size(); i++) {
            profit = max(profit, maxToRight[i] - prices[i]);
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Answer: " << s.maxProfit(prices) << endl;

    return 0;
}

