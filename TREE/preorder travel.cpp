/********************************************************************************************************************************************************************
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
******************************************************************************************************************************************************************/
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
    
    void preorder(TreeNode* root,vector<int>&v){
        
        
        if(!root)
            return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
            
 
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>v;
    
        preorder(root,v);
        return v;
        
    }
};

\*****************************************************************************************************************************************************************/
 
 ITERATIVE......
 
 vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode *node = root;
    stack<TreeNode*> st;
    while (node || st.size()) {
        if (node) {
            res.push_back(node->val);
            st.push(node);
            node = node->left;
        } else {
            node = st.top()->right;
            st.pop();
        }
    }
    return res;
}

/***************************************************************************************************************************************************************/

ITERATIVE TRAVERSAL......
 
 vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
     
    stack<TreeNode*> st;
    st.push(root);
    while (st.size()) {
        TreeNode* node = st.top();st.pop();
        res.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}

/*****************************************************************************************************************************************************************/

MORRISH TRAVERSAL.......
 
 void preorder(TreeNode* node, vector<int>& res) {
    while (node) {
        if (!node->left) {
            // output 1
            res.push_back(node->val);
            node = node->right;
        } else {
            TreeNode* tmp = node->left;
            while (tmp->right && tmp->right != node) tmp = tmp->right;
            if (tmp->right == nullptr) {
                tmp->right = node;
                // output 2
                res.push_back(node->val);
                node = node->left;                    
            } else {
                // clear 1
                tmp->right = nullptr;
                node = node->right;
            }                
        }
    }
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorder(root, res);
    return res;
}
 
