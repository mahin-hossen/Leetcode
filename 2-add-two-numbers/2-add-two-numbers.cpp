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
    void calculateCarry(int &sum,int &carry)
    {
        if(carry) carry--;
        if(sum>9)
        {
            sum-=10;
            carry++;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {   
        ListNode* newList = new ListNode();
        auto newHead = newList;
        int sum, carry = 0;
        
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;            
            calculateCarry(sum,carry);
            
            newList->next = new ListNode(sum);
            newList = newList->next;
        }
        
        while(l1)
        {
            sum = carry+ l1->val; 
            l1=l1->next;
            calculateCarry(sum,carry);
            
            newList->next = new ListNode(sum);            
            newList = newList->next;
        }
        while(l2)
        {
            sum = carry+ l2->val; 
            l2 = l2->next;
            calculateCarry(sum,carry);
            
            newList->next = new ListNode(sum);            
            newList = newList->next;
        }
        if(carry)
        {
            newList->next = new ListNode(carry);
            carry--;
        }            
        
        *newHead = *newHead->next;
               
        return newHead;
      
    }
};