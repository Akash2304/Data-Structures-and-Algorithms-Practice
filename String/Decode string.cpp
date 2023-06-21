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

/************************************************************************************************************************************************************************/
class Solution {
public:
    string decodeString(string s) {
         stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); nums.pop();
            }
        }
        return res;
    }
};

/*************************************************************************************************************************************************************************/
Intuition:-
After reading the question let's track some general terms like what type of observation will lead us to problem solving.
 In the question they told us about the repeatation and to show that there will be numbers outside the square brackets [...].
So we need to use this information of square brackets . Let's see how :

Before opening parenthesis we will get the number that we will be using for repeatations of our string .
when we get our closing parenthesis we will go back to our string letters to repeat them the number of
times the number and replace the originial part of that string and place i after that to continue .
Algorithm:-

Let's first initialize some variables and functions string repeat()->our helper function to repeat our substring that many number of times , 
 s->our final decoded string , repeatLetters->This are the letters that should be repeated , repeatTimes->Number of times the letters should be repeated .
Let's create a helper function which repeates the substring that many number of times the logic is quiet simple
After the first [ parenthesis we need to extract those letters to repeate that many times
After getting the decode part we will just replace the original encoded string with our repeated decoded string by the s.replace() built in method in c++
Code:-

//Comment and Upvote

class Solution {
public:
    //Function to help repeat the substring a number of times
    string repeat(string str,int times){
        string result="";
        for(int i=0;i<times;i++) result += str;
        return result;
    }
    string decodeString(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]!=']'){
                i++;
                continue;
            }
            //The string that needs to get repeated after the first parenthesis '['
            int j=i;
            while(s[j]!='[') j--;
            //The letters that we will be repeating
            string repeatLetters = s.substr(j+1,i-j-1);
            int k=j;
            j--;
            //checking the number before opening the parenthesis so we can get a count that how many times we need to repeat the strin
            while((j>0) && (isdigit(s[j])))
                j--;
            
            //Corner case : When we r at the start of our string
            if(j!=0) j++;
            //Find the number of times the letter should be repeated
            int repeatTimes = stoi(s.substr(j,k-j));
            //replace the encoded part of string with decoded part
            s.replace(j,i-j+1,repeat(repeatLetters,repeatTimes));
            //Putting i in the right place of our string
            i=j+repeatLetters.size()*repeatTimes;
        }
        return s;
    }
};
