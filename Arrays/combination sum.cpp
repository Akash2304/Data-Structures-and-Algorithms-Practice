/*********************************************************************************************************************************************************************
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers 
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen
numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 500
********************************************************************************************************************************************************************/

class Solution {
    void findNumbers(vector<int>& ar, int sum,
                 vector<vector<int> >& res, vector<int>& r,
                 int i)
{
    // if we get exact answer
    if (sum == 0) {
        res.push_back(r);
        return;
    }
 
    // Recur for all remaining elements that
    // have value smaller than sum.
    while (i < ar.size() && sum - ar[i] >= 0) {
 
        // Till every element in the array starting
        // from i which can contribute to the sum
        r.push_back(ar[i]); // add them to list
 
        // recursive call for next numbers
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;
 
        // Remove number from list (backtracking)
        r.pop_back();
    }
}
 
// Returns all combinations
// of ar[] that have given
// sum.
public:
    vector<vector<int>> combinationSum(vector<int>& ar, int sum) {
        
          sort(ar.begin(), ar.end());
 
    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());
 
    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, sum, res, r, 0);
 
    return res;
    }
};
