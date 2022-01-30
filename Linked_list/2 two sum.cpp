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
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(l1!=nullptr || l2 != nullptr){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = (a+b+carry)%10;
            if(sum >= 10){
                carry++;
            }
            if(head == nullptr){
                head = new ListNode(sum);
                tail = head;
            }
            else{
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            carry = (a+b+carry)/10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};