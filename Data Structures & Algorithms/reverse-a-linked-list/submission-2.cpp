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
    ListNode* reverseList(ListNode* head) {
        // save next to tmp
        // change next to prev
        
        if(!head) {
            return {};
        }

        ListNode* node = head;
        ListNode* prev = nullptr;

        while(node) {
            ListNode* tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        
//        node->next = prev;

        return prev;
    }
};