// Application of ------> 191. Number of 1 Bits


// Question :
// ""The Hamming distance between two integers is the number of 
// positions at which the corresponding bits are different.""
// return the sum of Hamming distances between all the pairs of the integers in nums.

//-------------------
// Idea
// multiply countOfOne with countOfZero(or n-countOne) for every bit


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> countOne(32,0);
        int n = nums.size();
        for(auto x: nums)
        {
            int ind = 31, temp = x;
            while(temp)
            {
                if(temp&1) countOne[ind]++;
                temp >>= 1;
                ind--;
            }
        }
        int ans = 0;
        for(int i=0; i<32; ++i)
        {
            ans += countOne[i]*(n-countOne[i]);
        }
        return ans;
    }
};