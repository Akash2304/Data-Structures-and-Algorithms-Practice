/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i,j=0;
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        for(i=1;i<intervals.size();i++)
        {
            if(v[j][1]>=intervals[i][0])
            {
                
                v[j][1]=max(v[j][1],intervals[i][1]);
            }
            else{
                j++;
                v.push_back(intervals[i]);
            }
            
        }
        return v;
        
    }
};
