#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        else if (list2 == nullptr) {
            return list1;
        }

        ListNode* minPtr;
        ListNode* minPtrPrev = nullptr;
        ListNode* list1Ptr = list1;
        ListNode* list2Ptr = list2;
        while (list1Ptr != nullptr && list2Ptr != nullptr) {
            bool list1Min = (list1Ptr->val < list2Ptr->val); 
            minPtr = list1Min ? list1Ptr : list2Ptr;
            if (list1Min) {
                list1Ptr = list1Ptr->next;
            } else {
                list2Ptr = list2Ptr->next;
            }

            if (minPtrPrev) {
                minPtrPrev->next = minPtr;
            }
            minPtrPrev = minPtr;
        }
        minPtr->next = list1Ptr != nullptr ? list1Ptr : list2Ptr; 
        return list1->val < list2->val ? list1 : list2;
    }
};

ListNode* createSinglyLinkedList(vector<int> values) {
    if (values.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* ptr = head;
    ListNode* nextPtr = nullptr;
    for (size_t i = 1; i < values.size(); i++) {
        nextPtr = new ListNode(values[i]);
        ptr->next = nextPtr;
        ptr = nextPtr;
    }
    return head;
}

void printSinglyLinkedList(ListNode* head) {
    if (head == nullptr) {
        cout << "nullptr" << endl;
    }

    ListNode* node = head;
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution s;

    vector<int> values1 = {1,2,4};
    vector<int> values2 = {1,3,4, 5, 6, 7};
    ListNode* list1 = createSinglyLinkedList(values1);
    ListNode* list2 = createSinglyLinkedList(values2);
    printSinglyLinkedList(list1);
    printSinglyLinkedList(list2);

    ListNode* mergedLists = s.mergeTwoLists(list1, list2);
    printSinglyLinkedList(mergedLists);

    return 0;
}

