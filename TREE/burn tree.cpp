/*********************************************************************************************************************************************************************
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 104
*********************************************************************************************************************************************************************/

class Solution {
  public:
  
  int res=0, he=-1;
    int height(Node* root)
    {
        if(root==NULL)
            return 0;
        else
            return max(height(root->left),height(root->right))+1;
    }
    int burn(Node* root, int target, int &dist)
    {
        if(root==NULL)
            return 0;
        if(root->data==target)
        {
            dist=0;
            he=height(root)-1;
            return 1;  
        }
        int ldist=-1,rdist=-1;
        int lh=burn(root->left,target,ldist);
        int rh=burn(root->right,target,rdist);
        
        if(ldist!=-1)
        {
            dist=ldist+1;
            res=max(res,rh+dist);
        }
        else if(rdist!=-1)
        {
            dist=rdist+1;
            res=max(res,lh+dist);
        }
        return max(lh,rh)+1;
    }
    int minTime(Node* root, int target) 
    {
          if(root->data==target)
        {
            return height(root)-1;
        }
        else{
            int d=-1;
            burn(root,target,d);
            return max(res,he);
        }
    }
};
