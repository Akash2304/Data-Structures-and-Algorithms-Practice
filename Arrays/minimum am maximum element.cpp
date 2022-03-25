/****************************************************************************************************************************************
Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

 

Example 1:

Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000
 

Example 2:

Input:
N = 5
A[]  = {1, 345, 234, 21, 56789}
Output:
min = 1, max = 56789

**************************************************************************************************************************************************************/
pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long,long long> arr(a[0],a[0]);
    for(int i=1;i<n;i++)
    {
        arr.first=min(a[i],arr.first);
        arr.second=max(a[i],arr.second);
    }
    return arr;
    
}
