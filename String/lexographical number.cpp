/*******************************************************************************************************************************************************************
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104
**********************************************************************************************************************************************************************/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string>s;
        for(int i=1;i<=n;i++)
            s.push_back(to_string(i));
        
        sort(s.begin(),s.end());
        
        vector<int>v;
        for(int i=0;i<n;i++)
            v.push_back(stoi(s[i]));
        
        return v;
        
    }
};
