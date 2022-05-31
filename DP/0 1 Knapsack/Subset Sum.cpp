/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

Ques: Given an array of non-negative integers, and a value sum, determine if there is a subset of given set with
      sum equal to given sum.

arr = {2, 3, 7} ; sum = 5

       0 1 2 3 4 5
{}     1 0 0 0 0 0
{2}    1 0 1 0 0 0
{3}    1 0 1 1 0 1
{7}    1 0 1 1 0 1

*/

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                int ind = j - arr[i - 1];
                if (j == 0)
                    dp[i][j] = 1;
                if (ind >= 0)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][ind];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};