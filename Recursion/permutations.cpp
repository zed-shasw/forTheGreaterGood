// https://leetcode.com/problems/permutations/
// ************* Scroll down for 2nd approach with optimized space complexity. ***************

// SOLUTION-1
// 1.) maintain a data structure that maintains if the element is visited or not.
// 2.) if it's not visited, push it into the data structures and mark the ds as visited
// 3.) after our ds size == arr.size(given array) then we push into our ans.

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
// 1.) Instead of using extra ds to maintain the pushed array as well as visited array we 
//     implement idea of swapping 
// 2.) In each step of recursion tree we swap nodes.

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