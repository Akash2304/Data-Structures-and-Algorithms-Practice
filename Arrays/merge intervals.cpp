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
