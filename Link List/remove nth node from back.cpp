/********************************************************************************************************************************************************************
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*********************************************************************************************************************************************************************/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        
        stack<ListNode*> st;
        ListNode *ptr = head;
        
        while(ptr!=NULL)
        {
            st.push(ptr);
            ptr = ptr->next;
        }
        
        ListNode *temp = NULL;
        while(n--)
        {
            temp = st.top();
            st.pop();
        }
        
        if(st.empty())
            return head->next;
        
        st.top()->next = temp->next;
        
        return head;
        
    }
};

/*******************************************************************************************************************************************************************/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;int c=0;
        while(head!=nullptr){
            c++;head=head->next;
        }
     int x=c-n-1;
        head=node;
        if(x==-1){
            head=head->next;}
            else{
        while(x--){
            if(node->next)
            node=node->next;
            
        }
            node->next=node->next->next;
            }        return head;
    }
};
