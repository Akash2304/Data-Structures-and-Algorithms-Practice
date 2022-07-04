/*******************************************************************************************************************************************************************
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
******************************************************************************************************************************************************************/
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
    ListNode* rotateRight(ListNode* head, int k) {
        int l=0,i;
        
    if(head==nullptr || k==0)
        return head;
        
        ListNode*temp=head;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        temp=head;
        vector<int>a;
        for(i=0;i<l;i++)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        
        if(l==k)
            return head;
        
        
        
        else if(l>k)
        {
            for(i=a.size()-k;i<a.size();i++)
            {
                temp->val=a[i];
                temp=temp->next;
            }
            for(i=0;i<a.size()-k;i++)
            {
                temp->val=a[i];
                temp=temp->next;
            }
        }
        else
        {
            k=k%l;
            
            for(i=l-k;i<a.size();i++)
            {
                temp->val=a[i];
                temp=temp->next;
            }
            for(i=0;i<l-k;i++)
            {
                temp->val=a[i];
                temp=temp->next;
            }
        }
        return head;
        
    }
};
