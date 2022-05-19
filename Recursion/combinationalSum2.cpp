// **************** https://leetcode.com/problems/combination-sum-ii/ *********************

// Intution : https://lh6.googleusercontent.com/xsb46oCfbNclHzkzuOZqiGDcST0giAlFSAjWC-FcXA4oYidD7n6DHq3qj4oJ4_qqSk4dzrozFM1V1yF5N237h5oo2rbQo3Y752QRDtZhyTGsEAz0_cEafV0V5uVF6kZmRpQbgetd

class Solution
{
public:
    void findCombination(int ind, int target, vector<int> arr, vector<int> &v, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int j = ind; j < arr.size(); ++j)
        {
            if (j > ind && arr[j] == arr[j - 1])
                continue;
            if (arr[j] > target)
                break;
            v.push_back(arr[j]);
            findCombination(j + 1, target - arr[j], arr, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        findCombination(0, target, candidates, v, ans);
        return ans;
    }
};