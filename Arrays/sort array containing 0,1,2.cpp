/*sort-an-array-of-0s-1s-and-2s  */

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int mid =0,low=0,high=n-1;
        while(mid<=high)
        {
            switch(a[mid])
            {
                case 0:
                {
                    swap(a[mid],a[low]);
                    low++;
                    mid++;
                    break;
                }
                case 1:
                {
                    
                    mid++;
                    break;
                }
                case 2:
                {
                    swap(a[mid],a[high]);
                    high--;
                    break;
                }
                
            }
        }
        
    }
    
};
