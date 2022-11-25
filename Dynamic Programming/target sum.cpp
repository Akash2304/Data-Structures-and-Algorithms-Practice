/********************************************************************************************************************************************************************
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
********************************************************************************************************************************************************************/

class Solution {
public:

int countsubsetsum(vector<int>v,int sum)
{

    int i,j;
    int t[v.size()+1][sum+1];
    for(i=0;i<=v.size();i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(i==0)
            t[i][j]=0;
            if(j==0)
            t[i][j]=1;
        }
    }
    for(i=1;i<=v.size();i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(v[i-1]<=j)
            t[i][j]=t[i-1][j]+t[i-1][j-v[i-1]];
            else
            t[i][j]=t[i-1][j];
        }
    }

    return t[v.size()][sum];
}
     
    int findTargetSumWays(vector<int>& nums, int target) {

        int s=0;
       for(int i=0; i<nums.size();i++){
					s += nums[i];
			}

           target=abs(target);
           if(nums.size()==1)
           if(nums[0]!=s)
           return 0;
        if(s<target||(s+target)%2!=0 )
            return 0;

        int s1=(target+s)/2;

        return countsubsetsum(nums,s1);
    }
};

/****************************************************************************************************************************************************************/

 //This question is same as number of subsets with given difference 
    int countSubsets(vector<int>& nums, int n, int M)
    {
        int t[n+1][M+1];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        //t[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][M];  
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int M=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
         return countSubsets(nums, n, M);
    }  

/*****************************************************************************************************************************************************************/


DP || Recursion + Memorization || C++|| Variation of Count Partitions with Given Difference

Jun LeetCoding Challenge
1
Oct 22, 2022
Intuition
Differnce b/w +ve and -ve is Target, its same as Count Partitions with Given Difference

Approach
S1 - S2 = Target , DP using Recursion + Memorization

Complexity
Time complexity:
O(N∗K)O(N*K)O(N∗K)

Space complexity:
O(N∗K)+O(N)O(N*K) + O(N)O(N∗K)+O(N)

Code
class Solution {
public:
   int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

	 if(ind == 0){
			if(target==0 && arr[0]==0)
					return 2;
			if(target==0 || target == arr[0])
					return 1;
			return 0;
	}

	if(dp[ind][target]!=-1)
			return dp[ind][target];

	int notTaken = countPartitionsUtil(ind-1,target,arr,dp);

	int taken = 0;
	if(arr[ind]<=target)
			taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);

	return dp[ind][target]= (notTaken + taken);
}

	int countPartitions(int d, vector<int>& arr){
			int n = arr.size();
			int totSum = 0;
			for(int i=0; i<arr.size();i++){
					totSum += arr[i];
			}

			if(totSum-d<0) return 0;
			if((totSum-d)%2==1) return 0;

			int s2 = (totSum-d)/2;

			vector<vector<int>> dp(n,vector<int>(s2+1,-1));
			return countPartitionsUtil(n-1,s2,arr,dp);
	}  
	int findTargetSumWays(vector<int>& nums, int target) {
        return   countPartitions(target,nums);
    }
};

/****************************************************************************************************************************************************************/
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        //Solution 1
        int sum = 0;
        for(int x : nums)
            sum += x;
        if(((sum - target) % 2 == 1) || (target > sum))
            return 0;
        
        int n = nums.length;
        int s2 = (sum - target)/2;
        int[][] t = new int[n + 1][s2 + 1];
        t[0][0] = 1;
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < s2 + 1; j++) {
                if(nums[i - 1] <= j)
                    t[i][j] = t[i-1][j] + t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][s2];
        
           //Solution 2
//         int sum = 0;
//         for(int x : nums)
//             sum += x;
//         if(((sum - target) % 2 != 0) || (target > sum))
//             return 0;
        
//         int n = nums.length;
//         int s2 = (sum - target)/2;
        
//         int[][] t = new int[n + 1][s2 + 1];
//         for(int i = 0; i < n + 1; i++) {
//             for(int j = 0; j < s2 + 1; j++) {
//                 if(i == 0)
//                     t[i][j] = 0;
//                 if(j == 0)
//                     t[i][j] = 1;
//             }
//         }
        
//         for(int i = 1; i < n + 1; i++) {
//             for(int j = 1; j < s2 + 1; j++) {
//                 if((nums[i - 1] > j) || (nums[i - 1] == 0))
//                     t[i][j] = t[i - 1][j];
//                 else
//                     t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
//             }
//         }
        
//         int count = 0;
//         for(int x : nums)
//             if(x == 0)
//                 count++;
        
//         return (int)(Math.pow(2,count)) * t[n][s2];
    }
}
