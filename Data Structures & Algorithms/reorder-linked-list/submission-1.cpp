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

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while(fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode* second = slow->next;
//         ListNode* prev = slow->next = nullptr;

//         while (second != nullptr) {
//             ListNode* tmp = second->next;
//             second->next = prev;
//             prev = second;
//             second = tmp;
//         }

//         ListNode* first = head;
//         second = prev;

//         while (second != nullptr) {
//             ListNode* tmp1 = first->next;
//             ListNode* tmp2 = second->next;
//             first->next = second;
//             second->next = tmp1;
//             first = tmp1;
//             second = tmp2;
//         }
//     }
// };


class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;

        vector<ListNode*> nodes;
        ListNode* cur = head;

        while(cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int i =0, j=nodes.size()-1;
        while(i<j) {
            nodes[i]->next = nodes[j];
            i++;
            if(i>=j) break;
            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};
