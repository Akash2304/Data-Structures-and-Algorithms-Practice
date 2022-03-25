/********************************************************************************************************************************************************
Given an array arr[] of N integers, calculate the median
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Example 2:

Input: N = 4
arr[] = 56 67 30 79
Output: 61
Explanation: In case of even number of 
elements, average of two middle elements 
is the median.

*********************************************************************************************************************************************************/

class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    if(v.size()%2!=0)
		    {
		        return v[(v.size()/2)];
		    }
		    else{
		        int ans=v[(v.size()/2)]+v[(v.size()/2)-1];
		        return ans/2;
		    }
		}
};
