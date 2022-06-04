/*****************************************************************************************************************************************************************
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

****************************************************************************************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,-1);
        int i,maxlen=0,start=-1;
        for(i=0;i<s.size();i++)
        {
            if(v[s[i]]>start)
                start=v[s[i]];
            v[s[i]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;
        
    }
};

*************************************************************************************************************************************************************
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int j=0;
        int maxx=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            while(mp[s[i]]>1)
            {
                mp[s[j]]--;
                j++;
            }
            maxx=max(maxx,i-j+1);
        }
        return maxx;
        
    }
};
