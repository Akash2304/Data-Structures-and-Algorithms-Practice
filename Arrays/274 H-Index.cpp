/**************************************************************************************************************************************************************************
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers
that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
**************************************************************************************************************************************************************************/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int>pq;

        for(auto i : citations)
        pq.push(i);

           int c=1;
           int flag=0;
           int val;
           int f1=0;
           int val2=INT_MIN;
        while(pq.empty()==false)
        {
                  val=pq.top();
                  if(val==0 && val2>c-1 )
                  {

                      return c-1;

                  }
                  if(val<c)
                  return c-1;

                     if(val==c)
                     {
                         flag=1;
                     break;
                     }
                     c++;

                     pq.pop();
                     val2=val;


        }


                int f=0;
                for(int i=0;i<citations.size();i++)
                {
                    if(citations[i]!=0)
                    {
                        f=1;break;
                    }

                }

        if( (f==0) ||(citations.size()==1 && citations[0]==0) )
        return 0;

        else{
            if(val>c)
            return c-1;
        if(flag==0)
        return 1;
        else{
            if(val>citations.size())
            return citations.size();
        return c;
        }
        }
        
        
    }
};

/*************************************************************************************************************************************************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=citations.size();
        
    int val=0;

        sort(citations.begin(),citations.end());

        for(int i=0;i<l;i++)
        if(citations[i]>=l-i){
            val=l-i;
            break;

        }
        return val;
        
    }
};
/*************************************************************************************************************************************************************************/
class Solution {
public:

int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}
};
