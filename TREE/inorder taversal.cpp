/****************************************************************************************************************************************************************
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
**************************************************************************************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==nullptr)
            return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>v;
         inorder(root,v);
        
        return v;
        
    }
};

\*****************************************************************************************************************************************************************/
 
 MORRISH TRAVERSAL..........
 
 void inorder(TreeNode* node, vector<int>& res) {
    while (node) {
        if (!node->left) {
            res.push_back(node->val);
            node = node->right;
        } else {
            TreeNode* tmp = node->left;
            while (tmp->right && tmp->right != node) tmp = tmp->right;
            if (tmp->right == nullptr) {
                tmp->right = node;
                node = node->left;                    
            } else {
                tmp->right = nullptr;
                res.push_back(node->val);
                node = node->right;
            }                
        }
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

\***************************************************************************************************************************************************************/
 
 ITERATIVE........
 
 vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while (node || st.size()) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            res.push_back(st.top()->val); // output
            node = st.top()->right;
            st.pop();
        }
    }
    return res;
}
