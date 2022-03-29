https://www.hackerrank.com/challenges/2d-array/problem



int hourglassSum(int arr_rows, int arr_columns, int** arr) {

    int i,j,k=0,s1=0,s2=0,S=0,maxsum=-63;       
    for(i=0;i<arr_rows-2;i++)
    {
        for(j=1;j<arr_columns-1;j++)
        {
            s1=arr[i][j-1]+arr[i][j]+arr[i][j+1];
            k=arr[i+1][j];
            s2=arr[i+2][j-1]+arr[i+2][j]+arr[i+2][j+1];

            S=s1+k+s2;
            if(maxsum<S){
            maxsum=S;
            }
        }
    }
     return maxsum;   



}
