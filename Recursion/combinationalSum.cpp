// *************** https://leetcode.com/problems/combination-sum/ ******************

// Here we implement the idea of pick and not pick, with repetation allowed unlimited number of times.

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

class Solution
{
public:
    void findCombination(int i, int target, vector<int> arr, vector<int> &v, vector<vector<int>> &ans)
    {
        if (i == arr.size())
        {
            if (target == 0)
                ans.push_back(v);
            return;
        }

        // pick the element...here we check if it's worth to pick the element.
        if (arr[i] <= target)
        {
            v.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, v, ans);
            v.pop_back();
        }
        // not pick the element
        findCombination(i + 1, target, arr, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        findCombination(0, target, candidates, v, ans);
        return ans;
    }
};