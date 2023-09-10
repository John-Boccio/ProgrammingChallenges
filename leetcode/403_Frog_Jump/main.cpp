#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class DynamicProgrammingSolution {
    
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1)
        {
            return false;
        }

        unordered_set<int> stonesSet;
        for (auto stone : stones)
        {
            stonesSet.insert(stone);
        }

        return canCross(stonesSet, 0, 1, *(stones.end()-1));
    }

    bool canCross(const unordered_set<int>& stonesSet, int position, int k, int targetStone) {
        bool km1Cross = false, kCross = false, kp1Cross = false;

        auto foundStone = stonesSet.find(position);
        if (foundStone == stonesSet.end())
        {
            return false;
        }
        if (*foundStone == targetStone) {
            return true;
        }

        if (k-1 > 0)
        {
            km1Cross = canCross(stonesSet, position + k - 1, k - 1, targetStone);
        }
        if (k > 0)
        {
            kCross = canCross(stonesSet, position + k, k, targetStone);
        }
        if (k+1 > 0)
        {
            kp1Cross = canCross(stonesSet, position+k+1, k+1, targetStone);
        }

        return km1Cross || kCross || kp1Cross;
    }
};

class RecursiveSolution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1)
        {
            return false;
        }

        unordered_set<int> stonesSet;
        for (auto stone : stones)
        {
            stonesSet.insert(stone);
        }

        return canCross(stonesSet, 0, 1, *(stones.end()-1));
    }

    bool canCross(unordered_set<int>& stonesSet, int position, int k, int targetStone) {
        bool km1Cross = false, kCross = false, kp1Cross = false;

        auto foundStone = stonesSet.find(position);
        if (foundStone == stonesSet.end())
        {
            return false;
        }
        if (*foundStone == targetStone) {
            return true;
        }

        if (k-1 > 0)
        {
            km1Cross = canCross(stonesSet, position + k - 1, k - 1, targetStone);
        }
        if (k > 0)
        {
            kCross = canCross(stonesSet, position + k, k, targetStone);
        }
        if (k+1 > 0)
        {
            kp1Cross = canCross(stonesSet, position+k+1, k+1, targetStone);
        }

        return km1Cross || kCross || kp1Cross;
    }
};

int main() {
    RecursiveSolution s;

    // vector<int> stones = {0,1,3,5,6,8,12,17};
    // vector<int> stones = {0,1,3};
    vector<int> stones = {0,2};

    cout << "Answer: " << s.canCross(stones) << endl;

    return 0;
}
