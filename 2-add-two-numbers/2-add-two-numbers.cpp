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
    void assignSum(int &sum,int &carry,ListNode* &newList)
    {
        if(carry) carry--;
        if(sum>9)
        {
            sum-=10;
            carry++;
        }
        newList->next = new ListNode(sum);
        newList = newList->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {   
        ListNode* newList = new ListNode();
        auto newHead = newList;
        int sum = 0, carry = 0;
        
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;            
            assignSum(sum,carry,newList);
        }
        
        while(l1)
        {
            sum = carry+ l1->val; 
            l1=l1->next;
            assignSum(sum,carry,newList);
        }
        while(l2)
        {
            sum = carry+ l2->val; 
            l2 = l2->next;
            assignSum(sum,carry,newList);
        }
        if(carry)
        {
            sum = 1;
            assignSum(sum,carry,newList);           
        }            
        
        *newHead = *newHead->next;
               
        return newHead;
      
    }
};