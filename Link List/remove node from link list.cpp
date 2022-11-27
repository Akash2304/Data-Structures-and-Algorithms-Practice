/*********************************************************************************************************************************************************************
You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
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
   ListNode* reverseList(ListNode* head) {
    ListNode *cur = head, *prev = nullptr;
    while (cur != nullptr) {
        swap(cur->next, prev);
        swap(prev, cur);
    }
    return prev;
}
ListNode* removeNodes(ListNode* head) {
    head = reverseList(head);
    for (auto p = head; p != nullptr && p->next != nullptr; ) {
        if (p->val > p->next->val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return reverseList(head);
}
};

/******************************************************************************************************************************************************************/

   ListNode* removeNodes(ListNode* head) {
        if (!head) return NULL;
        head->next = removeNodes(head->next);
        return head->next && head->val < head->next->val ?  head->next : head;
    }

/******************************************************************************************************************************************************************/

Stack
We maintain non-increasing stack of nodes. While the next value is larger, we pop nodes from the stack.

Then, we connect top-of-stack node to the next node, and push the next node to the stack.

C++

ListNode* removeNodes(ListNode* head) {
    ListNode tmp(INT_MAX);
    vector<ListNode*> st{ &tmp };
    for (auto p = head; p != nullptr; p = p->next) {
        while (st.back()->val < p->val) 
            st.pop_back();
        st.back()->next = p;
        st.push_back(p);
    }
    return tmp.next;
}

/******************************************************************************************************************************************************************/
Method 1
We will use postorder Recursion for removal of a node & will do elimination from right to left.

C++
 int maxi = 0;
 ListNode* removeNodes(ListNode* head) {
    if(head == nullptr) return head;
    head->next = removeNodes(head->next);
    if(head->val < maxi) return head->next;
    maxi = max(maxi, head->val);
    return head;
}
