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
        auto list = head;
        
        while(list && list->next)
        {
            if(list->val==list->next->val)
            {
                auto dummy = list->next->next;
                delete list->next;           
                list->next = dummy;                     
            }
                
            else list = list->next;
        }
        //5 5 5 3 3 
        return head;
    }
};