/*******************************************************************************************************************************************************************
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*****************************************************************************************************************************************************************/
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
    bool isPalindrome(ListNode* head) {
         if(head==nullptr)
        {
            return true;
        }
        vector<int>v;
        int i;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
                temp=temp->next;
        }
        i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if(v[i]==v[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
         }
                    return "true";
    }
        
    
};

/**************************************************************************************************************************************************************/
ListNode* tem = head;
stack st;
while(tem != NULL) {
st.push(tem->val);
tem = tem->next;
}
tem = head;
while(!(st.empty())) {
if(tem->val != st.top())
return false;
st.pop();
tem = tem->next;
}
return true;
