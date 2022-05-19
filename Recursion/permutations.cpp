// https://leetcode.com/problems/permutations/
// ************* Scroll down for 2nd approach with optimized space complexity. ***************

// SOLUTION-1 
void findWithExtraSpace(vector<int> arr, vector<int> &flag, vector<int> &v, vector<vector<int>> &ans)
    {
        if (v.size() == arr.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            if (!flag[i]) // not picked
            {
                v.push_back(arr[i]);
                flag[i] = 1; // marking it as picked
                findWithExtraSpace(arr, flag, v, ans);
                flag[i] = 0;
                v.pop_back();
            }
        }
    }


// ******************************************************************************************
// SOLUTION-2 : Without Extra Space

void findWithoutExtraSpace(int ind, vector<int> &arr, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = ind; i < arr.size(); ++i)
    {
        swap(arr[i], arr[ind]);
        findWithoutExtraSpace(ind + 1, arr, ans);
        swap(arr[i], arr[ind]);
    }
}