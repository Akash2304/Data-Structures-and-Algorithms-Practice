/*******************************************************************************************************************************************************************
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 
*******************************************************************************************************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
         string st = to_string(x);
        
       int n = st.size();
        
        for(int i=0;i<n/2;i++)
        {
            if (st[i]!=st[n-i-1])
            {
            return false;
                break;
            }
        
        }
        return true;
            

        
        
    }
};

/****************************************************************************************************************************************************************/
class Solution {
public:
stack<int>F;
queue<int>L;
bool isPalindrome(int x) {
    if(x<0)
        return false;
    int r;
    while(x!=0){
        r=x%10;
        L.push(r);
        F.push(r);
        x=x/10;

    }
    while(!L.empty() && !F.empty()){
        if(L.front()!=F.top()){
            return false;
        }
        L.pop();
        F.pop();
    }
    return true;

}
};
