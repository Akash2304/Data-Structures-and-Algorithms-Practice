/********************************************************************************************************************************************************************
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing 
the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence.
In this scenario, how would you change your code?
**********************************************************************************************************************************************************************/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(),m=t.length();
        int j = 0; 
    // For index of s (or subsequence
 
    // Traverse s and t, and
    // compare current character
    // of s with first unmatched char
    // of t, if matched
    // then move ahead in s
    for (int i = 0; i < m and j < n; i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of s were found in t
    return (j == n);
    }
};

/******************************************************************************************************************************************************************/

class Solution {
    int isSubSequence(string& s1, string& s2, int i, int j)
{
    if (i == 0 || j == 0) {
        return 0;
    }
    if (s1[i - 1] == s2[j - 1]) {
        return  1 + isSubSequence(s1, s2, i - 1, j - 1);
    }
    else {
        return  isSubSequence(s1, s2, i, j - 1);
    }
}
 
public:
    bool isSubsequence(string s, string t) {
         int m = s.size();
    int n = t.size();
    if (m > n) {
        return false;
    }
    if (isSubSequence(s, t, m, n) == m) {
        return true;
    }
    else {
        return false;
    }
    }
};

/******************************************************************************************************************************************************************/

class Solution {
public:
    
    bool isSubs(string& s, string& t, int m, int n)
    {
        if(m == 0)
            return true;
        if(n == 0)
            return false;
        
        // If last characters of two
        // strings are matching
        if (s[m - 1] == t[n - 1])
            return isSubs(s, t, m - 1, n - 1);
 
        // If last characters are
        // not matching
        return isSubs(s, t, m, n - 1);
    }
    
    
    bool isSubsequence(string s, string t) {
        
       if( isSubs(s,t,s.length(),t.length()))
           return true;
        
        return false;
        
    }
};

/**************************************************************************************************************************************************************/
class Solution {
public:
    
    // returns the length of longest common subsequence
    int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(s1[i-1] == s2[j-1])
            return t[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t);
        else
            return t[i][j] = isSubs(s1,s2,i,j-1,t);
    }
    
    
    bool isSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // intialising dp matrix with -1
        
        if(m >  n)
            return false;
        
        vector<vector<int>> t(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s1,s2,m,n,t) == m)
            return true;
        return false;
    }
};
