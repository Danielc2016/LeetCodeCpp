class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int temp = (0x7fffffff & (a & b) ) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};
