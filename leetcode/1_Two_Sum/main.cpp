#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2, 0);
        unordered_map<int, size_t> map;
        for (size_t i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            int requiredNum = target - nums[i];
            auto iter = map.find(requiredNum);
            if (iter != map.end() && iter->second != i)
            {
                return {static_cast<int>(i), static_cast<int>(iter->second)}; 
            }
        }

        return answer;
    }
};

int main() {
    Solution s;

    vector<int> input = {3,2,4};

    vector<int> answer = s.twoSum(input, 6);
    cout << "Answer: " << answer[0] << ", " << answer[1] << endl;

    return 0;
}

