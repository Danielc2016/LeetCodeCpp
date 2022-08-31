class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() - 1, m = b.length() - 1;
        string res = "";
        int carry = 0;
        while(n >= 0 || m >= 0 || carry)
        {
            if(n >= 0)
            {
                carry += ( a[n] - '0' );
                n--;
            }
            if(m >= 0)
            {
                carry += (b[m] - '0');
                m--;
            }
            res = char( carry % 2 + '0' ) + res;
            carry = carry / 2;
        }
        
        return res;
    }
};
