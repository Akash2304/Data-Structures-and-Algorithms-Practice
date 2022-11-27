/*********************************************************************************************************************************************************************
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

Example 1:

Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
Example 2:

Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
Example 3:

Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist only of lowercase English letters.
*********************************************************************************************************************************************************************/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        for (int i = 0; i < s.size() && j < t.size(); i++)
            j += s[i] == t[j];
        return t.size() - j;
        
    }
};

/*****************************************************************************************************************************************************************/

class Solution 
{
public:
    int appendCharacters(string s, string t) 
    {
        int count = 0;
        int m=s.size(), n=t.size();
        int i=0, j=0; 
        
        while(i<m && j<n)
        {
            if(s[i]==t[j]) //if character of both strings match move both pointers
            {
                i++;
                j++;
            }
            else //if character doesn't match then move string s pointer only
                i++;
        }
        
        if((j==n)) return 0; //if we covered whole t string then no need to append character
        return n-j;
        
    }
};

/****************************************************************************************************************************************************************/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int j  = 0;
        for(int i = 0 ; i < n && j < m ; i++)
        {
            if(s[i] == t[j])
            {
                j++;
            }
            
        }
        return (m-j);
    }
};
