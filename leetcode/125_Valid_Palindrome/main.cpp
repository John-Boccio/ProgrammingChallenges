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
    bool isPalindrome(string s) {
        string modifiedString = "";
        for (char c : s) {
            if (isalnum(c)) {
                modifiedString += tolower(c);
            }
        }

        for (size_t i = 0; i < modifiedString.size() / 2; i++) {
            if (modifiedString[i] != modifiedString[modifiedString.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    string str = "A man, a plan, a canal: Panama";
    cout << "String " << str << " is a palindrome? Answer: " << (s.isPalindrome(str) ? "YES" : "NO") << endl;

    return 0;
}

