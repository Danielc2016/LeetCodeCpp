class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int index = s.find_first_not_of(' ');
        if( index > s.length() )
            return res;
        int sign = 1;
        if (s[index] == '+' || s[index] == '-')
        {
            sign = s[index] == '-' ? -1 : 1;
            index++;
        }
        
        while (index < s.length() && isdigit(s[index])) {
            res = 10 * res + (int) (s[index] - '0');
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            index++;
        }
        return res * sign;
    }
};

