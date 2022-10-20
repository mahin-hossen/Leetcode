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
    ListNode* reverseList(ListNode* head) //3
    {
        //1 2 3 4 5
        //5 4 3 2 1
        /*
        1 2 3
        1->null
        */
        
        if(!head || !head->next) return head;
        auto reverseListHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reverseListHead;
        
        
        // if(!head) return head;
        // head->next = reverseList(head->next);                
        // return head;
        
    }
};