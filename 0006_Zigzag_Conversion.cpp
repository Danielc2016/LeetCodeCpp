class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string str = "";
        vector<string> temp(numRows, "");
        int row = 0, step = 1;
        for(int i = 0; i < s.size(); i++)
        {
            temp[row].push_back(s[i]);
            if(row==0)
                step = 1;
            else if(row == numRows - 1)
                step = -1;
            row += step;
        }
        for(string t : temp)
        {
            str += t;
        }
        return str;
        
    }
};
