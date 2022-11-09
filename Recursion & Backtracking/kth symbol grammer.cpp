/********************************************************************************************************************************************************************
We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each
occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 

Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
Example 2:

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01
Example 3:

Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
 

Constraints:

1 <= n <= 30
1 <= k <= 2n - 1
*******************************************************************************************************************************************************************/
class Solution {
public:
    
    int solve(int n,int k){
        if(n==1 && k==1)return 0;
        
        //finding mid :- 
        //as we can see length in each row inc by x2
        int mid = (pow(2,n-1))/2;
        
        //if k lies before mid 
        //say for nth row elements before mid
        //are equal to (n-1)th row.
        if(k <=mid)return solve(n-1,k);
        
        //else k lies after mid
        //which is equals to !(n-1)th row elements before mid.
        
        return !solve(n-1,k-mid);
    }
    int kthGrammar(int n, int k) {
        
        return solve(n,k);
    }
};
//0
//0 1
//0 1 1 0
//0 1 1 0 1 0 0 1
/*
here we can observe that length is getting twice in each row
and elements before mid of nth row is equal to (n-1)th row
and elements after mid of nth row is equals to !(n-1)th row elements.
*/
