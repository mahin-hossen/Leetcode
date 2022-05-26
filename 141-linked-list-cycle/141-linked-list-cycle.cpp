/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    
    bool hasCycle(ListNode *head) 
    {
        unordered_map<ListNode*,int> counter;        
        auto curr = head;
        
        while(curr)
        {
            counter[curr]++;
            if(counter[curr]>1) return true;
            curr = curr->next;
        }
        
        return false;
    }
};