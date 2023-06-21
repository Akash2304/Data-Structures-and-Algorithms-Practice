/******************************************************************************************************************************************************************
Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For a 1-byte character, the first bit is a 0, followed by its Unicode code.
For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

     Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
x denotes a bit in the binary form of a byte that may be either 0 or 1.

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer 
represents only 1 byte of data.

 

Example 1:

Input: data = [197,130,1]
Output: true
Explanation: data represents the octet sequence: 11000101 10000010 00000001.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

Input: data = [235,140,4]
Output: false
Explanation: data represented the octet sequence: 11101011 10001100 00000100.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
 

Constraints:

1 <= data.length <= 2 * 104
0 <= data[i] <= 255
*******************************************************************************************************************************************************************/
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 7)) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};

/******************************************************************************************************************************************************************/
Intuition:
Since we need to translate the provided data array into a sequence of valid UTF-8 encoded characters there is definitely an underlying concept of
bit manipulation to be used, let's see how we can achieve this.

Approach:

We will initially take a count variable initialized to 0;
Then we will iterate over the given array and will store the value from data array in ele = data[i]
If count is still 0 then below are the things that we need to take care of:
If x/32 = 110, then set count as 1. (x/32 is same as doing x >> 5 as 2^5 = 32)
Else if x/16 = 1110, then count = 2 (x/16 is same as doing x >> 4 as 2^4 = 16)
Else If x/8 = 11110, then count = 3. (x/8 is same as doing x >> 3 as 2^3 = 8)
Else if x/128 is 0, then return false. (x/128 is same as doing x >> 7 as 2^7 = 128)
Else if x/64 is not 10, then decrease the count and return false.
Finally if count is 0 return true;
C++:

class Solution{
public:
  bool validUtf8(vector<int> &data){
    int n = data.size(); 
    int count = 0;       
    for (int i = 0; i < n; i++){    
      int ele = data[i]; 
      if (!count){ 
	   // if the first 3 bits are 110, then the next byte is part of the current UTF-8 character
        if ((ele >> 5) == 0b110) 
          count = 1; 
		// if the first 4 bits are 1110, then the next 2 bytes are part of the current UTF-8 character  
        else if ((ele >> 4) == 0b1110)
          count = 2; 
		 // if the first 5 bits are 11110, then the next 3 bytes are part of the current UTF-8 character
        else if ((ele >> 3) == 0b11110)
          count = 3; 
		 // if the first bit is 1, then return false
        else if ((ele >> 7))
          return false; 
      }
      else{
	   // if the first 2 bits are not 10, then return false
        if ((ele >> 6) != 0b10)
          return false; 
        count--;        
      }
    }
    return (count == 0); 
  }
};
Time Complexity: O(N)
Space Complexity: O(1)
