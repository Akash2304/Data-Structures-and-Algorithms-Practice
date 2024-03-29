/****************************************************************************************************************************************************************************
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle.
The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
Example 2:


Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.
Example 3:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.
 

Constraints:

1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi, yi, ai, bi <= 105
***************************************************************************************************************************************************************************/
Intuition
Just used map to keep the count of edges.
Increasing the count of bottom left and top right vertices.
Decreasing the count of bottom right and top left vertices.
At Last We sum all the values of map.
If the value is 4 then return true as four vertices are there, else return false.

Approach
Create a map with key as pair of int and int(pair<int,int>);

Complexity
Time complexity:
O(N);

Space complexity:
Code
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;
        for(auto it:rectangles){
            m[{it[0],it[1]}]++;
            m[{it[2],it[3]}]++;
            m[{it[0],it[3]}]--;
            m[{it[2],it[1]}]--;
        }
        int cnt=0;
        for( auto it=m.begin();it!=m.end();it++){
            if(abs(it->second)==1){
                cnt++;
            }
            else if(abs(it->second)!=1&&it->second!=0){
                return false;
            }
        }
        return cnt==4;
    }
};
/************************************************************************************************************************************************************************/
