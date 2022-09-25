/********************************************************************************************************************************************************************
Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and
returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)


********************************************************************************************************************************************************************/

class Solution {
public:
    vector<int> factorial(int N){
          vector<int>v;
     
         v.push_back(1);
        
        
       
        for(int n =2;n<=N;n++)
        {
             int rem=0;
        for(int i=0; i<v.size(); i++)
            {
              int temp = v[i];
               int kk = (temp*n + rem)%10;
               v[i]=kk;
               rem = (temp*n + rem)/10;
            }
        
        while(rem!=0)
            {
                int xx = rem%10;
                v.push_back(xx);
                rem = rem/10;
            }
        
        } 
     reverse(v.begin(),v.end());
     return v;
   
    }
};

/*****************************************************************************************************************************************************************/
vector<int> factorial(int N){
        // code here
        vector<int> v;
        if(N==1||N==0)
        {
            v.push_back(1);
            return v;
        }
        string s ="1";
        for(int i=2;i<=N;i++)
        {   int len = s.size();
            int prod=0,r=0,carry=0; 
            for(int j=len-1;j>=0;j--)
            {
               prod = (s[j]-'0')*i+carry;
               r=prod%10;
               carry=prod/10;
               s[j]=r+'0';
            }
            while(carry>0)
            {
                int y = carry%10;
                carry = carry/10;
                char c = y+'0';
                s=c+s;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            v.push_back(s[i]-'0');
        }
        return v;
    }
