/********************************************************************************************************************************************************************
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*******************************************************************************************************************************************************************/
**iterative method*** 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
          if (root == NULL)
        return NULL;
 
    // search in left subtree
    TreeNode* leftt = kthSmallest(root->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (leftt != 0)
        return leftt;
 
    // if current element is k'th smallest, return it
    count++;
    if (count == k)
        return root;
 
    // else search in right subtree
    return kthSmallest(root->right, k);
    }
};

/*****************************************************************************************************************************************************************/

***recursive method***
