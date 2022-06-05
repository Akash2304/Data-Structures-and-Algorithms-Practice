/***************************************************************************************************************************************************************
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
******************************************************************************************************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        
    
        
        
        int l,h,start=0,end=1;
        int i;
        for(i=1;i<s.size();i++)
        {
            l=i-1;
            h=i;
            while(l>=0 && h<s.size() && s[l]==s[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;h++;
                
            }
            l=i-1;
            h=i+1;
            while(l>=0 && h<s.size() && s[l]==s[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;h++;
                
            }
            
        }
        return s.substr(start,end);
        
    }
};
