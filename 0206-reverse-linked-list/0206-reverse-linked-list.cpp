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
    ListNode* reverseList(ListNode* head) 
    {
        //1 2 3 4 5
        //5 4 3 2 1
        /*
        1 2 3
        1->null
        */
        ListNode *prev = nullptr, *curr;
        while(head)
        {            
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;        
        }
        return prev;
        
    }
};