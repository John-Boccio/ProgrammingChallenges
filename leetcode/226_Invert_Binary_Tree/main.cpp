#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <cctype>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode* createTree(vector<int>& values) {
        TreeNode* root = new TreeNode(values[0]);
        vector<TreeNode*> nodesAtLevel(1, root);
        vector<TreeNode*> nodesAtNextLevel;
        for (int level = 0; level < ceil(log(values.size())); level++) {
            int startingIdx = static_cast<int>(pow(2, level + 1)) - 1;
            for (size_t i = 0; i < nodesAtLevel.size(); i++) {
                TreeNode* node = nodesAtLevel[i];
                TreeNode* left = nullptr;
                TreeNode* right = nullptr;
                if (startingIdx + i*2 < values.size()) {
                    left = new TreeNode(values[startingIdx + i*2]);
                    nodesAtNextLevel.push_back(left);
                }
                if (startingIdx + i*2 + 1 < values.size()) {
                    right = new TreeNode(values[startingIdx + i*2 + 1]);
                    nodesAtNextLevel.push_back(right);
                }
                node->left = left;
                node->right = right;
            }
            nodesAtLevel = nodesAtNextLevel;
            nodesAtNextLevel.clear();
        }
        return root;
    }

    static void printInOrderTree(TreeNode* node) {
        printInOrderTreeHelper(node);
        cout << endl;
    }

    static void printInOrderTreeHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->val << " ";
        printInOrderTreeHelper(node->left);
        printInOrderTreeHelper(node->right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }

    void invertTreeHelper(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        TreeNode* tmp;
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        invertTreeHelper(node->left);
        invertTreeHelper(node->right);
    }
};

int main() {
    vector<int> values = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root = TreeNode::createTree(values);
    TreeNode::printInOrderTree(root);

    Solution s;
    s.invertTree(root);
    TreeNode::printInOrderTree(root);

    return 0;
}

