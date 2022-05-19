// T.C = O(2^n*n) , S.C = O(n)
// The idea is either pick or not pick...permutation 

void allSubsequence(int i, int n, int arr[], vector<int> &v)
{
    if (i == n)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
        return;
    }
    v.push_back(arr[i]);
    allSubsequence(i + 1, n, arr, v);
    v.pop_back();
    allSubsequence(i + 1, n, arr, v);
}