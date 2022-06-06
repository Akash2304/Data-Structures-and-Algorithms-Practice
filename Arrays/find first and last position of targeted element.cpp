/******************************************************************************************************************************************************************
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*******************************************************************************************************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> res ;
		
	
        int fidx , lidx;
        fidx = lidx = -1;
		
	
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target)
                high = mid - 1;
            else if(nums[mid] < target)
                low = mid + 1;
            else{
                fidx = lidx = mid;
                while(fidx >=0 && nums[mid] == nums[fidx]){
                    fidx--;
                }
                while(lidx <= nums.size() - 1 && nums[mid] == nums[lidx]){
                    lidx++;
                }
                fidx++;
                lidx--;
                break;
            }     
        }
        res.push_back(fidx);
        res.push_back(lidx);
        return res;
    }
        
};
