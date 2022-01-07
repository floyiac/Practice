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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* quick = head;
        ListNode* slow = dummy;
        for(int i=0;i<n;i++){
            quick = quick->next;
        }
        while(quick != nullptr){
            quick = quick->next;
            slow = slow -> next;
        }

        slow->next = slow->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};