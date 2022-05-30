// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Question : Given two integers left and right that represent the range [left, right], 
// return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right)      // until left is not equal to right we keep right shifting 
        {
            left>>=1;  // left = left>>1      
            right>>=1; // right = right>>1
            count++;
        }
        return left<<count;
    }
};