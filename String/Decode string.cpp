/********************************************************************************************************************************************************************
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a
positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the 
original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*********************************************************************************************************************************************************************/
class Solution {
public:
    string decodeString(string str) {
         stack<string> s;
 
        int i;
        for(i=0;i<str.length();i++){
            if(isdigit(str[i])){
                string temp = "";
                while(i<str.length() && isdigit(str[i])){
                    temp = temp + str[i];
                    i++;
                }
                s.push(temp);
            }
 
            if(str[i] != ']'){
                s.push(string(1, str[i]));
                continue;
            }
            else{
                string temp = "";
                while(!s.empty() && s.top() != "["){
                    temp = s.top() + temp;
                    s.pop();
                }
                s.pop();
 
                int x = stoi(s.top());
                s.pop();
                string y = "";
                while(x--){
                    y = y + temp;
                }
                s.push(y);
            }
        }
        string ans = "";
        while(!s.empty()){
            ans = s.top() + ans; 
            s.pop();
        }
 
        return ans;
        
    }
};
