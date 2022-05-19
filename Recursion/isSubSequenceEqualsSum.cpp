// Check if any subsequence sum equals to k(given sum) and print it.

// We implement the pick and not pick method here. 
// T.C = O(2^n*n) & S.C = O(n)

bool isSubSequenceEqualsSum(int i, int sum, int reqSum, int n, int arr[], vector<int> &v)
{
    if (i == n)
    {
        // condition satisfied
        if (sum == reqSum)
        {
            for (auto x : v)
                cout << x << " ";
            return true;
        }
        // condition not satisfied
        return false;
    }

    v.push_back(arr[i]);
    sum += arr[i];

    // pick
    if (isSubSequenceEqualsSum(i + 1, sum, reqSum, n, arr, v))
        return true;

    v.pop_back();
    sum -= arr[i];

    // not pick
    if (isSubSequenceEqualsSum(i + 1, sum, reqSum, n, arr, v))
        return true;

    return false;
}