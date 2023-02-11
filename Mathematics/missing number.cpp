/*******************************************************************************************************************************************************************
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
******************************************************************************************************************************************************************/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumOfNums = 0;
        for(int i=0; i<n; i++){
            sumOfNums += nums[i];
        }
        int sumOfNaturalNumber = (n*(n+1))/2;
        return sumOfNaturalNumber - sumOfNums;
    }
};

/******************************************************************************************************************************************************************/
/*

    Time Complexity : O(NlogN). Since we are using sorting.

    Space Complexity : O(1). Since we are not using any auxiliary space.

    Using Array + Sorting + Binary Search.

*/


/***************************************** Approach 1 *****************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(nums[mid] <= mid){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};






/*

    Time Complexity : O(N). Since we are traversing the array only once.

    Space Complexity : O(1). Since we are not using any auxiliary space.

    Using Array + Xor.

*/


/***************************************** Approach 2 *****************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, i;
        for(i=0; i<nums.size(); i++){
            res = res ^ nums[i] ^ i;
        }
        return res^i;
    }
};






/*

    Time Complexity : O(N). Since we are traversing the array only once.

    Space Complexity : O(1). Since we are not using any auxiliary space.

    Using Array + Math.

*/


/***************************************** Approach 3 *****************************************/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumOfNums = 0;
        for(int i=0; i<n; i++){
            sumOfNums += nums[i];
        }
        int sumOfNaturalNumber = (n*(n+1))/2;
        return sumOfNaturalNumber - sumOfNums;
    }
};
