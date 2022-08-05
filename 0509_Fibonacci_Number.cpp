class Solution {
public:
    int fib(int n) {
        int prev = 0;
        int curr = 1;
        if(n < 3)
            return n==0 ? prev : curr;
        for(int i=2; i <= n; ++i)
        {
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
