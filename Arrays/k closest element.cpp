/*******************************************************************************************************************************************************************
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*********************************************************************************************************************************************************************/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k==arr.size()) return arr;
        int a=0,b=1;
        for(int i=2; i<arr.size();i++)
        {
            if(abs(arr[i]-x)<=abs(arr[b]-x))
            {
                a=b;
                b=i;
            }
        }
        
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            if(a>=0 && b<arr.size())
            {
                if(abs(arr[a]-x)<=abs(arr[b]-x)) a--;
                else b++;
            }
            else if(a<0 && b<arr.size()) b++;
            else a--;
        }
        for(int i=1; i<=k; i++) ans.push_back(arr[a+i]);
        return ans;
    }
};
