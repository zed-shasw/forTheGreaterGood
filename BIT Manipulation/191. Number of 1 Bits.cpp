// Write a function that takes an unsigned integer 
// and returns the number of '1' bits it has 
// (also known as the Hamming weight).

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        uint32_t mask=1; // mask for extracting 1's
        
        while(n)   //n>0
        {
            if(mask&n)        // extract the lsb 
                count++;      // increment the count
            n >>= 1;          // shift the bits right by 1.
        }
        return count;
    }
};