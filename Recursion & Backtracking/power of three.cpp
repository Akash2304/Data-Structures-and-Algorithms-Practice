/********************************************************************************************************************************************************************
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?
*******************************************************************************************************************************************************************/
bool isPowerOfThree(int n) {
	if(n <= 1) return n == 1;
	return n % 3 == 0 && isPowerOfThree(n / 3);
}
/********************************************************************************************************************************************************************/
class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const MaxInt32 = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};
/*********************************************************************************************************************************************************************/
public class Solution {
public boolean isPowerOfThree(int n) {
    // 1162261467 is 3^19,  3^20 is bigger than int  
    return ( n>0 &&  1162261467%n==0);
}
  /*****************************************************************************************************************************************************************/
  bool isPowerOfThree(int n) {
	if(!n) return false;
	while(n % 3 == 0) n /= 3;    
	return n == 1;
}
