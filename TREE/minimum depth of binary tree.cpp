/********************************************************************************************************************************************************************

*****************************************************************************************************************************************************************/
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

**TIME LIMIT EXCEED CODE**

class Solution {
public:

 
      int height(TreeNode*root){
              if(root==nullptr)
              return 0;

              else if(height(root->left) && height(root->right))
              return (min(height(root->left),height(root->right))+1);
              else

              return (max(height(root->left),height(root->right))+1);
           
      }
    int count(TreeNode*root)
    {
        if(root==nullptr)
        return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        if(lh && rh)
        return min(lh,rh)+1;
        else if(lh)
        return lh+1;
        else
        return rh+1;
    }
    int minDepth(TreeNode* root) {
        return count(root);
    }
};

/***************************************************************************************************************************************************************/

*** FULL WORKING CODE PASSEs ALL TEST CASES***
class Solution {
public:
    int minDepth(TreeNode* root) {

        if (!root) return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
        
    }
};

/***************************************************************************************************************************************************************/

BFS CODE..

int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int i = 0;
    while (!Q.empty()) {
        i++;
        int k = Q.size();
        for (int j=0; j<k; j++) {
            TreeNode* rt = Q.front();
            if (rt->left) Q.push(rt->left);
            if (rt->right) Q.push(rt->right);
            Q.pop();
            if (rt->left==NULL && rt->right==NULL) return i;
        }
    }
    return -1; //For the compiler thing. The code never runs here.
}
/*****************************************************************************************************************************************************************/
