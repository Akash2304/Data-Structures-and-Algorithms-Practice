/******************************************************************************

You are given an array a1,a2,…,an of positive integers. A good pair is a pair of indices (i,j) with 1≤i,j≤n such that, for all 1≤k≤n, the following equality holds:

|ai−ak|+|ak−aj|=|ai−aj|,
where |x| denotes the absolute value of x.

Find a good pair. Note that i can be equal to j.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) where ai is the i-th element of the array.

The sum of n for all test cases is at most 2⋅105.

Output
For each test case, print a single line with two space-separated indices i and j which form a good pair of the array. The case i=j is allowed. It can be shown that such a pair always exists. If there are multiple good pairs, print any of them.

Example
inputCopy
3
3
5 2 7
5
1 4 2 2 3
1
2
outputCopy
2 3
1 2
1 1

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];

        int max=INT_MIN;
        int min=INT_MAX;
        int minindex,maxindex;
        if(n==1)
        cout<<1<<" "<<1<<endl;

        else{
        for(i=0;i<n;i++)
        {
            if(a[i]>max)
            {
            max=a[i];
                maxindex=i;
            }
            if(a[i]<min)
            {
                min=a[i];
               minindex=i;
            }
        }
        cout<<minindex+1<<" "<<maxindex+1<<endl;

            }
    }

    return 0;
}
