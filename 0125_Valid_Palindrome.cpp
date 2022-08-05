class Solution {
public:
    bool isPalindrome(string s) {
        //remove non-alphanumeric and convert to lower
        //s.erase(remove(s.begin(), s.end(), ' '), s.end());
        // not only spaces so use isalnum
        string str = "";
        for(int i = 0; i < s.size(); i++)
            if(isalnum(s[i]))
                str += s[i];
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int j = str.length() - 1;
        int i = 0;
        while( i <= j )
        {
            if(str[i]!=str[j])
                return false;
            i++, j--;
        }
        return true;
    }
};
