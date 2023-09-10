#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stac.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (stac.size() == 0) {
                    return false;
                }

                if (c == ')' && stac.top() != '(') {
                    return false;
                }
                else if (c == '}' && stac.top() != '{') {
                    return false;
                }
                else if (c == ']' && stac.top() != '[') {
                    return false;
                }
                else {
                    stac.pop();
                }
            }
        }
        return stac.size() == 0;
    }
};

int main() {
    Solution s;

    string str = "([)]";
    cout << "Answer: " << (s.isValid(str) ? "VALID" : "INVALID") << endl;

    return 0;
}

