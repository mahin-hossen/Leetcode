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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *mergedListHead = new ListNode();
        auto mergedList = mergedListHead;
        
        while(list1 && list2)
        {            
            if(list1->val < list2->val)
            {
                // mergedList->next = new ListNode(list1->val);
                mergedList->next = list1;
                list1 = list1->next;
            }
            else
            {
                mergedList->next = list2;
                list2 = list2->next;
            }
            mergedList = mergedList->next;
        }
        
        while(list1)
        {
            mergedList->next = list1;
            mergedList = mergedList->next;
            list1 = list1->next;
        }
        while(list2)
        {
            mergedList->next = list2;
            mergedList = mergedList->next;
            list2 = list2->next;
        }
        
        return mergedListHead->next;        
    }
};