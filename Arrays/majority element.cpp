/*********************************************************************************************************************************************************************
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*********************************************************************************************************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
         int z;
        for(auto x:nums)
        {
            mp[x]++;
        }
        for(auto i:mp)
        {
            if(i.second>nums.size()/2)
               {
                   z=i.first;
                   break;
               }
        }
        return z;
    }
};
