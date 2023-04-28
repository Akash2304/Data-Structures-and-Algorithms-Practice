/********************************************************************************************************************************************************************
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*******************************************************************************************************************************************************************/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
          int i=0;
          int l1=word1.length();
          int l2=word2.length();
        if(l1>l2)
        {
            while(word2[i])
            {
                s+=word1[i];
                s+=word2[i];
                i++;
            }
            while(word1[i])
            {
                s+=word1[i];
                i++;
            }
        }
        else if(l2>l1)
        {
            while(word1[i])
            {
                s+=word1[i];
                s+=word2[i];
                i++;
            }
            while(word2[i])
            {
                s+=word2[i];
                i++;
            }
        }
        else{
            while(word1[i])
            {
                s+=word1[i];
                s+=word2[i];
                i++;
            }
        }
        return s;
    }
};

/****************************************************************************************************************************************************************/
Two Pointers

// TC: O(n + m)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = word1.size(), m = word2.size();
        // i to point to word1, j to point word2
        int i = 0, j = 0;
        while (i + j < m + n) {
            // add i-th character from word1
            if(i < n) ans += word1[i++];
            // add j-th character from word2
            if(j < m) ans += word2[j++];
        }
        return ans;
    }
};

/****************************************************************************************************************************************************************/
One Pointer

// TC: O(n + m)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = word1.size(), m = word2.size();
        for(int i = 0; i < n || i < m; i++) {
            // add i-th character from word1
            if(i < n) ans += word1[i];
            // add i-th character from word2
            if(i < m) ans += word2[i];
        }
        return ans;
    }
};
