/*********************************************************************************************************************************************************************
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
********************************************************************************************************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {

                if(s.size()!=t.size())
                return false;
        vector<int>v(26,0);
        vector<int>v1(26,0);
               

        for(int i=0;i<s.size();i++){
        v[s[i]-97]++;
        v1[t[i]-97]++;
        }

        for(int i=0;i<26;i++)
        {
            if(v[i]!=v1[i]  )
            return false;
        }

        return true;

    }
};

/******************************************************************************************************************************************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};

/*****************************************************************************************************************************************************************/

Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate the unordered_map 
and speed up the code. The following implementation takes 12 ms.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};

/****************************************************************************************************************************************************************/
Sorting

For two anagrams, once they are sorted in a fixed order, they will become the same. This code is much shorter (this idea can be done in just 1 line using Python 
as here). However, it takes much longer time --- 76 ms in C++.

class Solution {
public:
    bool isAnagram(string s, string t) { 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};
