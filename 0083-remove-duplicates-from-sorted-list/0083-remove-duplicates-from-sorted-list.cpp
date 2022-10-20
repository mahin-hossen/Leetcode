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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *curr = new ListNode(-1,head);
        auto newHead = curr;
        
        for(;head && head->next;head=head->next)
        {            
            if(head->next->val == head->val) continue;            
            curr->next = head;
            curr = curr->next;            
        }
        
        if(head) curr->next = head;
        
        return newHead->next;
    }
};