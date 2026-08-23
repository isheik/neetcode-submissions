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
        // compare 2 lists
        // grab one with lower value, make that new head
        // then, compare 2
        // proceed with next nodes until the other lists has equal smaller value
        // if smaller is find, then
        // 1. change the current node next to the other list node
        // 2. change the other list node's next 

        ListNode dummy(0);
        ListNode* node = &dummy;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if(list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        return dummy.next;
    }
};
