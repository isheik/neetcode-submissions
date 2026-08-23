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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* sum = new ListNode();

        ListNode* cur = sum;
        int carry = 0;

        while(l1 && l2) {
            int s = l1->val + l2->val + carry;

            if(s >= 10) {
                carry = 1;
                cur->val = s%10; 
                //carry
            } else {
                carry = 0;
                cur->val = s;
            }
            
            cout << cur->val << endl;
             if(l1->next || l2->next) {
            ListNode* node = new ListNode();
                        cur->next = node;
                                    cur = cur->next;
             }

            l1 = l1->next;
            l2 = l2->next;

        }

        while(l1) {
            int s = l1->val + carry;

            if(s >= 10) {
                carry = 1;
                cur->val = s%10; 
                //carry
            } else {
                carry = 0;
                cur->val = s;
            }

//            cur->val = l1->val;
            if(l1->next) {
            ListNode* node = new ListNode();
            cur->next = node;
                                    cur = cur->next;
            }
            l1 = l1->next; 


        }
        while(l2) {
            int s = l2->val + carry;

            if(s >= 10) {
                carry = 1;
                cur->val = s%10; 
                //carry
            } else {
                carry = 0;
                cur->val = s;
            }

//            cur->val = l2->val;
if(l2->next) {
            ListNode* node = new ListNode();
            cur->next = node;
                                    cur = cur->next;
}
            l2 = l2->next; 
                       // cur = cur->next;
        }
        if(carry == 1) {
            ListNode* node = new ListNode(1);
            cur->next = node;
        }
        // cout << "test" << endl;
        // while(sum) {
        //     cout << sum->val <<endl;
        //     sum = sum->next;
        // }

        return sum;
    }
};
