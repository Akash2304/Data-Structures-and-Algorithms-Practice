/*********************************************************************************************************************************************************************
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?

SAME FOR POWER OF TWO 
*********************************************************************************************************************************************************************/

class Solution {
    public boolean isPowerOfFour(int n) {
        if(n<1){
            return false;
        }
        if(n%4==0){
            return isPowerOfFour(n/4);
        }
        return n==1;
    }
}

/**************************************************************************************************************************************************************/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n&0x55555555);
		// n>0, n should be positive
		// n&(n-1) ensure it is power of 2
		// 5 is "0101" so n&0x55555... ensure that set bit is at the even position.
		// soo if n is power of 2 and set bit is at even position -> n is power of 4
    }
};


OR

bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
/*************************************************************************************************************************************************************/
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 1) {
            if(num % 4)return false;
            num /= 4;
        }
        return num == 1;
    }
};

