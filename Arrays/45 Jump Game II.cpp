/****************************************************************************************************************************************************************************
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
**************************************************************************************************************************************************************************/
class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,sabsejyada=0,aakhrijagah=0,jump=0;

        while(aakhrijagah<nums.size()-1)
        {
            sabsejyada=max(sabsejyada,i+nums[i]); 
            
            //yaha se maxx nikaaal rahe upto jump last position tak kaaa  utne ineterval mai current index and upto i+that index value...

            if(i==aakhrijagah)
            {
                aakhrijagah=sabsejyada;  
                
                   //jaha tak jump ho rahi hai startse unke beeechh mai jo v maxx aa rhaaa usko store krr rhe taaki minimum jump aa sake.....

                jump++;
            }
            i++;

        }
        return jump;
        
    }
};
