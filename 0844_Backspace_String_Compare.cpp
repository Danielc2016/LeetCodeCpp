class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // don't need to check if its the same size
        int sizeS = s.length(), sizeT = t.size();
        string strS = "", strT = "";
        for(char& c: s)
        {
            if( c != '#')
                strS += c;
            else
            {
                if(strS.length() == 0)
                    continue;
                else
                    strS.pop_back();
            }
        }
        for(char& c : t)
        {
            if( c != '#')
                strT += c;
            else
            {
                if(strT.length() == 0)
                    continue;
                else
                    strT.pop_back();
            }
        }
        return (strT==strS);
    }
};
