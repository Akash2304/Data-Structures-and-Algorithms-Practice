/********************************************************************************************************************************************************************
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
******************************************************************************************************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        string ans="";
    int n=strs.size();
    
    sort(strs.begin(),strs.end());      // O(nlogn),in this all get sorted acc to their                                                character if last and first letters are equal                                                 mean in between every string has certain letters                                              common
    
    int p=min(strs[0].size(),strs[n-1].size());    // store min(size of 1st word/string, size of last word/string)
    
    string first=strs[0];             // store first word 
    string last=strs[n-1];           // store last word 
    
    int i=0;
    
    while(i<p && first[i]==last[i]){        // O(max no. of characters)
        ans=ans+first[i];                  // store all matching characters
        i++;
    }
          
    return ans;
    
    }
};
