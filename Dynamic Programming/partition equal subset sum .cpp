/********************************************************************************************************************************************************************
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets 
is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*********************************************************************************************************************************************************************/
class Solution {
public:

bool subset(vector<int>v,int sum)
{
int i,j;
bool t[v.size()+1][sum+1]; //dp

for(i=0;i<=v.size();i++)
{
    for(j=0;j<=sum;j++)
    {
        if(i==0)
        t[i][j]=false;

        if(j==0)
        t[i][j]=true;
   }
}

for(i=1;i<=v.size();i++)
{
    for(j=1;j<=sum;j++)
    {

        if(v[i-1]<=j)
        t[i][j]=(t[i-1][j-v[i-1]] || t[i-1][j]);
        else
        t[i][j]=t[i-1][j];
    }
}

return t[v.size()][sum];

}
    bool canPartition(vector<int>& nums) {

           int sum=0;

           for(int i=0;i<nums.size();i++)
           sum=sum+nums[i];

           if(sum%2!=0)
           return false;
           else
           return subset(nums,sum/2);
        
    }
};

/*****************************************************************************************************************************************************************/

public boolean canPartition(int[] nums) {
    int sum = 0;
    
    for (int num : nums) {
        sum += num;
    }
    
    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;
    
    int n = nums.length;
    boolean[] dp = new boolean[sum+1];
    Arrays.fill(dp, false);
    dp[0] = true;
    
    for (int num : nums) {
        for (int i = sum; i > 0; i--) {
            if (i >= num) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
    }
    
    return dp[sum];
}

/****************************************************************************************************************************************************************/

✔️ Solution - IV (Dynamic Programming - Tabulation)

We can convert the dp approach to iterative version. Here we will again use dp array, where dp[sum] will denote whether sum is achievable or not. Initially, 
we have dp[0] = true since a 0 sum is always achievable. Then for each element num, we will iterate & find if it is possible to form a sum j by adding num to
some previously formable sum.

One thing to note that it is essential to iterate from right to left in the below inner loop to avoid marking multiple sum, say j1 as achievable and then again 
using that result to mark another bigger sum j2 (j2=j1+num) as achievable. This would be wrong since it would mean choosing num multiple times. So we start from
right to left to avoid overwriting previous results updated in the current loop.

C++

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};

/***************************************************************************************************************************************************************/

  
