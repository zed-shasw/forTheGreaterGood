// We need to return the count of subsequence having sum equals to given sum(i.e. k)

// Pick or Not Pick approach with simple modifications.
// T.C = O(2^n*n) & S.C = O(n)

int countSubSequenceEqualsSum(int i, int sum, int reqSum, int n, int arr[])
{
    if (i == n)
    {
        // condition satisfied
        if (sum == reqSum)
            return 1;
        // condition not satisfied
        return 0;
    }

    sum += arr[i];
    // pick
    int l = countSubSequenceEqualsSum(i + 1, sum, reqSum, n, arr);

    sum -= arr[i];
    // not pick
    int r = countSubSequenceEqualsSum(i + 1, sum, reqSum, n, arr);

    return l + r;
}