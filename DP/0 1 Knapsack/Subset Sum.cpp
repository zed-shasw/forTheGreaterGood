/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

Ques: Given an array of non-negative integers, and a value sum, determine if there is a subset of given set with
      sum equal to given sum.

arr = {2, 3, 7} ; sum = 5

       0 1 2 3 4 5
{}     0 0 0 0 0 0
{2}    0 0 1 0 0 0
{3}    0 0 1 1 0 2
{7}    0 0 1 1 0 2

*/

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            int ind = j - arr[i - 1];  // check if it is possible to consider the element. 
            if (ind >= 0)
            {
                if (ind == 0 || dp[i - 1][ind])   // if adding element makes sense 
                    dp[i][j] = 1 + dp[i - 1][ind];
                else                              // else insert the value from last row  
                    dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum] > 0;
}