/******************************************************************************************************************************************************************
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

******************************************************************************************************************************************************************/
class Solution {
public:
    string convert(string s, int t) {
        if(t==1)
            return s;
        string ans="";
        int n=s.size();
        vector<string>v(t);
        bool flag=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            v[j].push_back(ch);
            (flag)?j--:j++;
            if(j==t)
            {
                flag=1;
                j-=2;
            }
            else if(j==-1)
            {
                flag=0;
                j+=2;
            }   
        }
        for(string st:v)
            ans+=st;
        return ans;
        
    }
};
