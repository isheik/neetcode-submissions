// Solved by myself, but codes were messy
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

// original codes by me
// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         if(!head || !head->next) {
//             return false;
//         }

//         ListNode* fast = head;
//         ListNode* slow = head;

//         fast = fast->next->next;
//         slow = slow->next;
//         int count = 0;

//         while(fast && slow && (fast != slow)) {
//             if(!fast->next) {
//                 return false;
//             }
//             fast = fast->next->next;
//             slow = slow->next;
//             count++;
//             if(count == 2000) {
//                 return false;
//             }
//         }

//         if(!fast || !slow) {
//             return false;
//         } 

//         return true;
//     }
// };

// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         ListNode* fast = head;
//         ListNode* slow = head;

//         while(fast && fast->next) {
//             fast = fast->next->next;
//             slow = slow->next;
//             if(fast == slow) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };


class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        ListNode* cur = head;

        while(cur) {
            if(seen.find(cur) != seen.end()) {
                return true;
            }
            seen.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

