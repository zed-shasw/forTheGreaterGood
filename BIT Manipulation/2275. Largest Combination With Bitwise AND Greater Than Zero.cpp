// ***********************************************************************************
// Question : Return the size of the largest combination of candidates with a 
// bitwise AND greater than 0.


// candidates = [16,17,71,62,12,24,14]
// 16 --> 0 0 1 0 0 0 0
// 17 --> 0 0 1 0 0 0 1
// 71 --> 1 0 0 0 1 1 1
// 62 --> 0 1 1 1 1 1 0
// 12 --> 0 0 0 1 1 0 0
// 24 --> 0 0 1 1 0 0 0
// 14 --> 0 0 0 1 1 1 0
    
// count [1 1 4 4 4 3 2]        

// since highest count of 1 is 4, so the answer is 4

// ***********************************************************************************

          // https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/ 

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> countOnes(32,0);        // store the count of 1 considering input as 32 bit
        for(int i=0;i<n; ++i)
        {
            int temp = 31;
            while(candidates[i] > 0)
            {
                countOnes[temp] += candidates[i]%2;
                candidates[i] /= 2;
                temp--;
            }
        }
        int ans = *max_element(countOnes.begin(),countOnes.end()); 
        return ans;
    }
};