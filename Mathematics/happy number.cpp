/********************************************************************************************************************************************************************
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*********************************************************************************************************************************************************************/
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

/******************************************************************************************************************************************************************/
hash-set

The hash-set solution is very straightforward. For every new data, we check whether it is already in the set. If no, we insert it into the set. If yes, we detect the loop. Only when the node in the loop is "1", the number is happy number.

The code is as follow. The time complexity is O(nlogn) (due to the sort function).

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        
        while(n != 1)
        {
            if(tmp.find(n) == tmp.end())
                tmp.insert(n);
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};

/*****************************************************************************************************************************************************************/
hash-map

The idea is similar as hase-set. We check the node value to check whether it is in the loop.

The code is as follow. The time complexity usually is O(1) (the worst may be O(n) due to conflict)

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> tmp;
        
        while(n != 1)
        {
            if(tmp[n] == 0)
                tmp[n]++;
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};

/*****************************************************************************************************************************************************************/


