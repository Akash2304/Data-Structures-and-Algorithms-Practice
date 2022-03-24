/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

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
