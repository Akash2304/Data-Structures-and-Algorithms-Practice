/********************************************************************************************************************************************************************
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

 

Example 1:


Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree.
The answer is the yellow node from the cloned tree.
Example 2:


Input: tree = [7], target =  7
Output: 7
Example 3:


Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.
 

Follow up: Could you solve the problem if repeated values on the tree are allowed?
*******************************************************************************************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
          if (cloned == NULL)
            return cloned;
        if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
            ans = cloned;
        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);
        return ans;
    }
};

/*****************************************************************************************************************************************************************/
TreeNode* getTargetCopy(TreeNode* orig, TreeNode* clone, TreeNode* targ) {
  return orig == nullptr ? nullptr :
    orig == targ ? clone : 
      getTargetCopy(orig->left, clone->left, targ) ?: getTargetCopy(orig->right, clone->right, targ);
}

/*****************************************************************************************************************************************************************/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if( original == NULL ){
            // Base case aka stop condition
            // empty tree or empty node
            return NULL;
        }
        
        // General case:
        if( original == target ){
            // current original node is target, so is cloned
            return cloned;
        }
        
        // Either left subtree has target, or right subtree has target
        TreeNode *left =  getTargetCopy(original->left, cloned->left, target);
        
        if( left != NULL ){ 
            return left; 
        
        }else{
            return getTargetCopy(original->right, cloned->right, target);
        }
        
    }
};

/*********************************************************************************************************************************************************/
