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
/*
TC : 0(n)
MC : 0(1)
*/
class Solution 
{
public:

    int getDecimalValue(ListNode* head) 
    {
        auto currNode = head;
        int decVal = 0;
        
        while(currNode)
        {
            decVal = decVal*2 + currNode->val;
            currNode = currNode->next;
        }
        
        return decVal;
        
    }
};