/*******************************************************************************************************************************************************************
You are given a string S, the task is to reverse the string using stack.

 

Example 1:


Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
 

Your Task:
You don't need to read input or print anything.
Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ length of the string ≤ 100

 
*****************************************************************************************************************************************************************/
char* reverse(char *S, int len)
{
    int i;
    stack<char>s;
    
    for(i=0;i<len;i++)
    {
        s.push(S[i]);
    }
    for(i=0;i<len;i++)
    {
        S[i]=s.top();
        s.pop();
    }
    return S;
}
