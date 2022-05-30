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
    void reverseHalfList(ListNode* prevNode,ListNode* &curr)
    {  
        ListNode* prev = NULL;
        while(curr)
        {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;            
        }     
        prevNode->next = prev;
        
        return;        
    }
    
    int pairSum(ListNode* head) 
    {
        auto slow = head, fast = head;
        
        while(fast->next && fast->next->next)//until fast reaches on sec last element
        {
            slow = slow->next;
            fast = fast->next->next;
        }        
        
        reverseHalfList(slow,slow->next);//reverses half of list
        
        slow = slow->next;//slow is on half of list
        auto curr = head;
        
        int maxTwinSum = INT_MIN;
        while(slow)
        {
            int currPairSum = curr->val+slow->val;
            maxTwinSum = max(currPairSum,maxTwinSum);
            
            slow = slow->next;
            curr = curr->next;
        }
        
        return maxTwinSum;
    }
};