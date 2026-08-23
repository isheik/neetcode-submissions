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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) {
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        fast = fast->next->next;
        slow = slow->next;
        int count = 0;

        while(fast && slow && (fast != slow)) {
            if(!fast->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            count++;
            if(count == 2000) {
                return false;
            }
        }

        if(!fast || !slow) {
            return false;
        } 

        return true;
    }
};
