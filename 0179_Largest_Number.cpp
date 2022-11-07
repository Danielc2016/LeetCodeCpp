class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        auto comp = [&] (string& a, string& b)
        {
            return (a + b) > (b + a);
        };
        vector<string> numsStr;
        for(auto& num : nums)
        {
            numsStr.push_back(to_string(num));
        }
        sort(numsStr.begin(), numsStr.end(), comp);
        for(auto& str : numsStr)
        {
            res += str;
            if(res[0] == '0') // to avoid string length_error
                return "0";
        }

        return res;
    }
};

/*
Largest:

Brute Force: N^2
    Sort:
        3, 5, 9, 30, 34
    num / 10 : 

Sort: NlogN

*/
