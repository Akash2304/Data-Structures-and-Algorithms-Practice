/*******************************************************************************************************************************************************************
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 

Constraints:

1 <= n <= 1000
*******************************************************************************************************************************************************************/
class Solution {
public:
    int pivotInteger(int n) {
        
        int s=(n*(n+1))/2;
        int s1=0;
        
        int flag=0;
        
        while(s1<s)
        {
            s1=s1+n;
            if(s1==s)
            {
                flag=1;
                break;
            }
            
            s=s-n;
            n--;
        }
        
        if(flag==1)
            return n;
        else
            return -1;
        
    }
};

/*****************************************************************************************************************************************************************/
int pivotInteger(int n) {
    int sum = n * (n + 1) / 2, x = sqrt(sum);
    return x * x == sum ? x : -1;
}

/****************************************************************************************************************************************************************/

DP
Since pivot increases with n, we can compute pivot for the entire range in O(n).

Then, a query will take O(1). The overal complexity will be amortized O(1).

C++
Note that dp is global so it's populated once then reused between test cases.

int dp[1001] = { 0, 0 };
class Solution {
public:
int pivotInteger(int n) {
    if (dp[1] == 0)
       for (int i = 1, j = 1; i <= 1000; ++i) {
           int sum = i * (i + 1) / 2;
           while (j * j < sum)
               ++j;
           dp[i] = j * j == sum ? j : -1;
       }
    return dp[n];
}
};
