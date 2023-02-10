/********************************************************************************************************************************************************************
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.

 

Example 1:

Input: n = 9
Output: 6
Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 109
*******************************************************************************************************************************************************************/
Timt Limit Exceeded

class Solution {
  
public:
    int lastRemaining(int n) {
        vector<int>v1;
        vector<int>v2;
        
        for(int i=1;i<=n;i++)
            v1.push_back(i);
        
        while(v1.size()!=1 &&v2.size()!=1)
        {
           
            for(int i=0;i<v1.size();i++)
            {
                if(i%2 !=0)
                    v2.push_back(v1[i]);
              }
            
            while(v1.size()>0)
                v1.pop_back();
            
            if(v2.size()==1)
                return v2[0];
            
            if(v2.size()%2==0){
            for(int i=v2.size()-1;i>=0;i--)
            {
                if(i%2==0)
                    v1.push_back(v2[i]);
            }
            }
            else{
                 for(int i=v2.size()-1;i>=0;i--)
            {
                if(i%2 !=0)
                    v1.push_back(v2[i]);
            }
                  }
            while(v2.size()>0)
                v2.pop_back();
            reverse(v1.begin(),v1.end());
            
          }
        if(v1.size()==1)
            return v1[0];
        else
            return v2[0];
        
    }
};

/******************************************************************************************************************************************************************/
After first elimination, all the numbers left are even numbers.
Divide by 2, we get a continuous new sequence from 1 to n / 2.
For this sequence we start from right to left as the first elimination.
Then the original result should be two times the mirroring result of lastRemaining(n / 2).

int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}
/*****************************************************************************************************************************************************************/
Two Pointer Concept

class Solution {
public:
    bool changeBothPtr(int& left, int& right, int& step) {
        return !((right - left) % step);
    }

    int lastRemaining(int n) {
        int left = 1, right = n, step = 2, pos = 0;

        while (left < right) {
            if (changeBothPtr(left, right, step)) {
                left+= (step / 2);
                right-= (step / 2);
            }
            else {
                if (pos) right-= (step / 2);
                else left+= (step / 2);
            }
            pos = 1 - pos;
            step*= 2;
        }
        return left;
    }
};
/*****************************************************************************************************************************************************************/

I conclude these rules into my code:

remain starts as n, divide by 2 each row, stop the loop when remain=1.
Integer step caches the distance the head might need to move, starts as 1, multiply by 2 each row.
direction starts as ->, turn around each row.
when direction is ->, the head move forward;
when direction is <-, the head move forward if remain is odd, else does nothing.
class Solution {
public:
    int lastRemaining(int n) {
        int head=1, step=1;
        bool direction=true; //t for ->, f for <-;
        while (n>1) {
            if (direction)
                head+=step;
            else
                head+=n%2==0?0:step;
            step*=2;
            n/=2;
            direction=!direction;
        }
        return head;
    }
};
/*******************************************************************************************************************************************************************/
