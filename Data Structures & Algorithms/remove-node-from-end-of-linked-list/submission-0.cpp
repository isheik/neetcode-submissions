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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = 0;
//         ListNode* node = head;

//         while(!node) {
//             len++;
//             node = node->next;
//         }

//         int prev = len - n;
//         node = head;

//         len = 0;

//         if(prev == 0) {
//             if(head->next) {
//                 return head->next;
//             } else {
//                 return nullptr;
//             }
//         }

//         while(!node) {
//             len++;
            
//             if(prev == len) {
//                 if(node->next) {
//                     cout << "yattemasu" << endl;
//                     node->next = node->next->next;
//                 }
//             }

//             node = node->next;
//         }

//         return head;
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while(n>0) {
            right = right->next;
            n--;
        }

        while(right!=nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};
