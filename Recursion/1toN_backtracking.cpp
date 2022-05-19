class Solution{
public:
    void print_1toN(int n, int cnt)
    {
      if(cnt < 1) return;
      print_1toN(n, cnt-1); 
      printf("%d\n", cnt); // here
    }

    void print1toN_backtracking(int n)
    {
      print_1toN(n,n);
    }
};