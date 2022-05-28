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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        auto currNode = head, nthNode = head;
        ListNode* prevNode = nullptr;
        
        while(n--)
        {
            currNode = currNode->next;
        }
        
        while(currNode)
        {
            prevNode = nthNode;
            currNode = currNode->next;            
            nthNode = nthNode->next;
        }
        
        if(prevNode == nullptr)
        {
            head = head->next;
        }
        else
        {
            prevNode->next = nthNode->next;
        }       
        
        delete(nthNode);        
        return head;
    }
};