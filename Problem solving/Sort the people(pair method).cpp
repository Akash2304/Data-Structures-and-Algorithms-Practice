/**********************************************************************************************************************************************************************
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*********************************************************************************************************************************************************************/

1. With Vector of Pairs
Just sort the pair vector in which we will store the height in first part of pair.

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> A;
        int N = names.size();
        for(int i = 0; i < N; i++) {
            A.push_back({heights[i], names[i]});
        }

        sort(A.rbegin(), A.rend());

        vector<string> ans;
        for(int i = 0; i < N; i++) {
            ans.push_back(A[i].second);
        }
        return ans;
    }

/******************************************************************************************************************************************************************/

2. Priority Queue 

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        priority_queue<pair<int, string>> pq;
        
        for(int i = 0; i < heights.size(); i++){
            pq.push({heights[i], names[i]});
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
}
