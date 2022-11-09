/*********************************************************************************************************************************************************************
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
**********************************************************************************************************************************************************************/
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
 bool is_same(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2)) return false;
        
        if(root1->val == root2->val) return is_same(root1->left , root2->right) && is_same(root1->right , root2->left);
        else return false;
    }
    
    
    bool isSymmetric(TreeNode* root) {
          return is_same(root->left, root->right);
    }
};

/**************************************************************************************************************************************************************/

DFS Solution:-

class Solution {
public:
    bool checkSymmetric(TreeNode* lft,TreeNode* rgt){
        if(lft==NULL || rgt==NULL)
            return lft==rgt;
        if(lft->val!=rgt->val)
            return false;
        return (checkSymmetric(lft->left,rgt->right) && checkSymmetric(lft->right,rgt->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        if(checkSymmetric(root->left,root->right))
            return true;
        return false;
    }
};

/****************************************************************************************************************************************************************/
BFS Solution:-

class Solution {
public:
    bool checkPalin(vector<int> vec){
        int n=vec.size(),i=0,j=n-1;
        while(i<j){
            if(vec[i++]!=vec[j--])
                return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            int size=que.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                    vec.push_back(node->left->val);
                }
                else
                    vec.push_back(-101);
                if(node->right){
                    que.push(node->right);
                    vec.push_back(node->right->val);
                }
                else
                    vec.push_back(-101);
            }
            if(!checkPalin(vec))
                return false;
        }
        return true;
    }
};
