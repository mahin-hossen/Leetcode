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
class Solution 
{
public:
    int getLength(ListNode* head)    
    {
        int len = 0;
        auto currNode = head;
        
        while(currNode->next)
        {             
            len++;
            currNode = currNode->next;
        }
        
        return len;
    }
    int getDecimalValue(ListNode* head) 
    {
        
        int len = getLength(head);
        auto currNode = head;
        int decValue = 0;
        
        while(currNode)
        {
            if(currNode->val)
            {
                decValue+=1<<len;
            }            
            len--;
            currNode = currNode->next;
        }
        
        return decValue;
        
    }
};