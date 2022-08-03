/********************************************************************************************************************************************************************
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*******************************************************************************************************************************************************************/
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
    
    void postorder(TreeNode*root,vector<int>&v){
        if(!root)
            return;
        
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>v;
        
        postorder(root,v);
        
        return v;
        
    }
};

\*************************************************************************************************************************************************************\
sol2: iterative - reverse of preorder............

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while (node || st.size()) {
        if (node) {
            res.push_back(node->val);
            st.push(node);
            node = node->right;
        } else {
            node = st.top()->left;
            st.pop();
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

\******************************************************************************************************************************************************\
sol3:iterative...........

void postorder(TreeNode* node, vector<int>& res) {
    stack<TreeNode*> st;
    TreeNode* lastVisit = nullptr;
    while(node || st.size()) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            TreeNode* peek = st.top();
            if (peek->right && peek->right != lastVisit) {
                node = peek->right;
            } else {
                res.push_back(peek->val);
                st.pop();   
                lastVisit = peek;
            }
        }
    }
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
}

/**************************************************************************************************************************************************************/

MORRISH TRAVERSAL......
 
 void postorder(TreeNode* node, vector<int>& res) {
    while (node) {
        if (node->right) {
            TreeNode* tmp = node->right;
            while(tmp->left && tmp->left != node) tmp = tmp->left;
            if (!tmp->left) {
                res.push_back(node->val);
                tmp->left = node;
                node = node->right;
            } else {
                tmp->left = nullptr;
                node = node->left;
            }
        } else {
            res.push_back(node->val);
            node = node->left;
        }
    }
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return vector<int>(res.rbegin(), res.rend());
}
